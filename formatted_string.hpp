#include <string_view>
#include <array>
#include <utility>
#include <algorithm>
#include <experimental/array>
#include <functional>

namespace fr
{
    namespace helper
    {
        template<size_t N>
        struct Formatted_string_wrapper
        {
            static constexpr auto formatters = std::experimental::make_array<char (*)(char)>(
                    [](char c){
                        return c >= 'a' && c <= 'z' ? static_cast<char>(c - 32) : c;
                    },
                    [](char c){
                        return (c == ' ' || c == '-') ? '_' : c;
                    },
                    [](char c){
                        return
                            (c > 'Z' || c < 'A') &&
                            (c < '0' || c > '9') &&
                            (c != '_') ? '?' : c;
                    }
            );

            using Func = typename decltype(formatters)::value_type;

            static constexpr auto formatting_function_wrapper = [](Func formatter) {
                return [formatter](std::pair<char, bool>& result)
                {
                    auto& [c, formatted] = result;
                    if(auto proposed = formatter(c); !formatted && c != proposed)
                    {
                        c = proposed;
                        formatted = true;
                    }
                };
            };

            static constexpr auto format = [](char c)
            {
                auto result = std::pair{c, false};
                std::ranges::for_each(formatters, [&result](auto func)
                {
                    formatting_function_wrapper(func)(result);
                });
                return result.first;
            };

            template<auto ... ints>
            static constexpr std::array<char, N>
            formatted_string_helper(std::string_view sv, std::index_sequence<ints...>)
            {
                return {format(sv[ints])...};
            }

            std::array<char, N> _char_arr;

            constexpr explicit operator std::string_view() const noexcept
            {
                return std::string_view(_char_arr.begin(), _char_arr.end());
            }
        };
    }

    template<size_t N>
    consteval auto make_formatted_string(const char (&sv)[N])
    {
        std::array<char, N - 1> arr =
                helper::Formatted_string_wrapper<N - 1>::formatted_string_helper(sv, std::make_index_sequence<N - 1>{});
        return helper::Formatted_string_wrapper<N - 1>{arr};
    }
} // namespace fr