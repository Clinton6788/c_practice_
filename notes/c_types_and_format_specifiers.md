# C Types and `printf` Format Specifiers

## Variables

C is statically typed: each variable has a declared type. The type
determines the kind of value it can represent and affects how operations
on it are performed.

``` c
int quantity;
double price;
char category;

quantity = 12;
price = 19.99;
category = 'A';
```

A declaration introduces a variable and specifies its type. Assignment
gives an already-declared variable a value.

You can also declare and initialize in one statement:

``` c
int quantity = 12;
```

## Fundamental types

  -----------------------------------------------------------------------
  Type                    General purpose         Example
  ----------------------- ----------------------- -----------------------
  `char`                  Character-sized integer `'A'`
                          type; commonly used for 
                          characters              

  `int`                   Integer values          `42`

  `float`                 Single-precision        `3.14f`
                          floating-point value    

  `double`                Double-precision        `3.14159`
                          floating-point value    

  `void`                  Represents no value /   `void function(void)`
                          no type                 
  -----------------------------------------------------------------------

Important notes:

-   Exact type sizes are implementation-dependent, subject to minimum
    ranges specified by C.
-   `sizeof(type)` reports a type's size in bytes on the current
    implementation.
-   `float` and `double` cannot represent every decimal fraction
    exactly.
-   A `char` stores an integer value. It is not a string.
-   C has no built-in string type. Strings are represented using arrays
    of characters terminated by a null character (`'\\0'`).
-   `void` is commonly used to indicate that a function returns no value
    or accepts no parameters.

## Integer type variations

C provides signed and unsigned integer types, along with different
minimum widths.

``` c
short int small_number;
int normal_number;
long int large_number;
long long int very_large_number;

unsigned int nonnegative_count;
```

-   `signed` integer types can represent negative and positive values.
-   `unsigned` integer types represent nonnegative values.
-   The exact ranges depend on the implementation.
-   Use `<stdint.h>` types such as `int32_t` and `uint64_t` when an
    exact-width integer type is required and provided by the
    implementation.

## `printf` format specifiers

`printf` is declared in `<stdio.h>`. Format specifiers tell it how to
interpret and display the corresponding argument.

``` c
#include <stdio.h>

int main(void)
{
    int quantity = 12;
    double price = 19.99;
    char category = 'A';

    printf("Quantity: %d\\n", quantity);
    printf("Price: %.2f\\n", price);
    printf("Category: %c\\n", category);

    return 0;
}
```

  |Specifier              | Expected argument      | Purpose                |
  |:--                    | :--                    | :--                    |
  |`%d`                   | `int`                  | Signed decimal integer|
  |`%i`                   | `int`                  | Signed decimal integer|
  |`%u`                   | `unsigned int`         | Unsigned decimal integer|
  |`%ld`                  | `long int`             | Signed long integer|
  |`%lld`                 | `long long int`        | Signed long long integer|
  |`%f`                   | `double`               | Decimal floating-point notation|
  |`%e`                   | `double`               | Scientific notation|
  |`%g`                   | `double`               | Chooses `%f` or `%e` representation|
  |`%c`                   | `int` (character value)| Character|
  |`%s`                   | Pointer to a null-terminated character array| String|
  |`%p`                    |`void *`                |Pointer address (representation is implementation-defined)|

### Precision and width

A precision after the decimal point controls the number of digits
displayed after the decimal for `%f`, `%e`, and `%g` (with `%g`
precision having different significant-digit semantics).

``` c
double price = 19.999;

printf("%.2f\\n", price);   // 20.00
printf("%10.2f\\n", price); // Right-aligned in a field at least 10 characters wide
printf("%-10.2f!\\n", price); // Left-aligned
```

For `%f`, the default precision is six digits after the decimal point.
`%.2f` displays two digits after the decimal point.

## Important `printf` distinction: `float` and `double`

When passed as an argument to `printf`, a `float` is automatically
promoted to `double`. Therefore, `%f` is used for both `float` and
`double` values with `printf`.

This differs from `scanf`, which uses different format specifiers for
`float *` and `double *`. Do not assume `printf` and `scanf` use
identical rules.

## Escape sequences

Escape sequences represent special characters inside string and
character literals.

  Sequence   Meaning
  ---------- ----------------
  `\\n`      New line
  `\\t`      Horizontal tab
  `\\\\`     Backslash
  `\\"`      Double quote
  `\\'`      Single quote
  `\\0`      Null character

Example:

``` c
printf("First line\\nSecond line\\n");
```

## Type conversions

C can convert values between arithmetic types. Some conversions happen
implicitly; others can be requested with a cast.

``` c
int quantity = 12;
double price = 19.99;

double total = quantity * price; // int is converted for the calculation
int rounded_down = (int)price;   // Explicit cast; fractional part is discarded
```

A cast changes how an expression is converted; it does not guarantee
that the value is preserved. Converting a floating-point value to an
integer discards the fractional part, truncating toward zero.

We'll cover conversion rules, integer division, overflow, and precision
in more detail as we work through arithmetic.
