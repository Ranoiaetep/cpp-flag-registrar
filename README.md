# C++ Flag Registrar
![Requirement](https://img.shields.io/badge/requirements-C%2B%2B20-success?logo=C%2B%2B)
![Dependency](https://img.shields.io/badge/dependency-Boost-blue?logo=data:image/png;base64,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)
![CMake build](https://img.shields.io/github/workflow/status/Ranoiaetep/cpp-flag-registrar/CMake?logo=github)
![Codacy grade](https://img.shields.io/codacy/grade/134d7730640349c98a7cae5319250a30?logo=codacy)

Header-only compile time flag registrar written in C++20.

## Usage

### Register

To register flags: `constexpr auto my_reg = MAKE_REGISTRAR("foo bar", "Hello, world!", "abc")`.

This will generate a mapping of: 
```yaml
{"FOO_BAR",         0x0001}
{"HELLO?_WORLD?",   0x0010}
{"ABC",             0x0100}
```
Each string supplied to `MAKE_REGISTRAR` will be registered to 2<sup>N</sup>.
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

C++20 is required, along with [Boost/Preprocessor](https://www.boost.org/doc/libs/1_76_0/libs/preprocessor/doc/index.html) and [Boost/Hana](https://www.boost.org/doc/libs/1_61_0/libs/hana/doc/html/index.html) libraries.