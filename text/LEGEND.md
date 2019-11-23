### Game Board

	 ___o   o___
	|  .-. .-.  |
	| .-.-.-.-. |
	|.-.-.-.-.-.|
	|-.-.-.-.-.-|
	|.-.-.-.-.-.|
	|-.-.-.-.-.-|
	|.-.-.-.-.-.|
	|-.-.-.-.-.-|
	|.-.-.-.-.-.|
	|-.-.-.-.-.-|
	|     -     |
	|____% %____|

### Parts

+ Ramp: `/` `\`
+ Crossover: `X`
+ Bit: `<` (0) `>` (1) `^` (0 or 1)
+ Interceptor: `U`
+ Gearbit: `{` (0) `}` (1)
+ Gear: `*`

### Setup syntax

`B b R r ( ) | ? * + [0-9]`

+ `B` and `R`: blue and red marble generators.
+ `b` and `r`: halted marbles.
+ `? * + [0-9]`: prefix quantifiers for marbles.
+ `( ) |`: regular expressions grouping and alternation.

