# C++ Flag Registrar
![Requirement](https://img.shields.io/badge/requirements-C%2B%2B20-blue?logo=C%2B%2B)
![CMake build](https://img.shields.io/github/workflow/status/Ranoiaetep/cpp-flag-registrar/CMake?logo=github)
![Codacy grade](https://img.shields.io/codacy/grade/134d7730640349c98a7cae5319250a30?logo=codacy)

Header-only compile time flag registrar written in C++20.

## Usage
### Register
To register flags: 
```cxx
constexpr auto FOO_FLAG = 
    fr::make_registrar<"foo bar", "Hello, world!", "abc123">();
```
Or:
```cxx
using namespace fr::literals;

constexpr auto FOO_FLAG = 
    fr::make_registrar_k("foo bar"_k, "Hello, world!"_k, "abc123"_k);
// note the usage of user-defined literal `_k`
```
Or:
```cxx
MAKE_REGISTRAR(FOO, "foo bar", "Hello, world!", "abc123");
// a constexpr variable named `FOO_FLAG` will be automatically created
```
Each of them will generate a mapping of: 
```yaml
{"FOO_BAR",           0x0001}
{"HELLO?_WORLD?",     0x0010}
{"ABC123",            0x0100}
```
Each string supplied will be registered to 2<sup>N</sup>.
- Note that original string are [formatted](#formatting) by default.

### Retrieving

- To retrieve a single flag: 
  ```cxx
  my_reg("FOO")
  ```
  - If the given flag does not exist, a compile-time error will be thrown.
- To retrieve multiple flags: 
  ```cxx
  my_reg("FOO", "BAR", ...)
  ```
  - This would be equivalent to calling:
  ```cxx
  my_reg("FOO") | my_reg("BAR") | ...
  ```
- Alternatively, you can use the user-defined literal `_k` to supply an unformatted string:
  ```cxx
  using namespace fr::literals;
  
  my_reg("foo"_k, "bar"_k, "hello, world?"_k)
  ```
  - Note with literal `_k`, supplied flag does **not** need to match the original key. As long as they will be formatted to the same result, it will be a match.

### Formatting

- By default:
  - All alphabets will be capitalized:
    - `abc` --> `ABC`
  - Space`' '`,dash`-`, underscore`_` will be formatted to underscore `_`:
    - `A-B C_D` --> `A_B_C_D`
  - All other special characters will be formatted to question mark`?`
    - `A@B!C+D` --> `A?B?C?D`
  - Numbers will remain unchanged
    

- Alternatively, you can supply your own formatter:
  ```cxx
  #define FLAG_REGISTER_CUSTOM_FORMATTER my_formatter

  constexpr auto my_formatter = [](auto c){
      if(c == 'z')
          return '@';
      return c;
  };
    ```
  - Now the original string will be formatted by replacing all `z` to `@`

# Prerequisites

- C++20 with range library support is required for now, ~~along with [Boost/Preprocessor](https://www.boost.org/doc/libs/1_76_0/libs/preprocessor/doc/index.html) and [Boost/Hana](https://www.boost.org/doc/libs/1_61_0/libs/hana/doc/html/index.html) libraries.~~ 
- C++14/17 support will be added later.