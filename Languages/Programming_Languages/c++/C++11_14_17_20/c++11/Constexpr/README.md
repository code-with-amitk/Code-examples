## constexpr
- **What** Compiler “tries its best” to evaluate constexpr expression at compile-time, but not guaranteed. consteval is proper guarantee.

- **Constexpr vs Macro**
||macro|constexpr|
|---|---|---|
|Type|int|unsigned|
|When to use|Use constexpr whenever you may|macros only if no other solution is possible|
