## Challenge #19: Entanglement

### Objective

If the top bit AND the bottom bit start pointed to the right, intercept a blue ball. Otherwise, intercept a red ball.

### Setup 1

`balls:8B-8R; start:B; trace:b|rB`

### Solution 1

	 ___o    ___
	|  .\. .\.  |
	| .-.\.-.\. |
	|.-.-.^.-.\.|
	|-.-.\.\.-./|
	|.-.-.^./.\.|
	|-.-./.\.-./|
	|.-./.-.\./.|
	|-./.-.-.X.-|
	|.-.\.-./.\.|
	|-.-.\./.-./|
	|     U     |
	|____% %____|

### Setup 2

`balls:8B-8R; start:B; trace:b|rB`

### Solution 2

	 ___o    ___
	|  .\. ./.  |
	| .-.\.\.-. |
	|.-.-.^.\.-.|
	|-.-.\.\./.-|
	|.-.-.^.X.-.|
	|-.-.\.X./.-|
	|.-.-./.\.-.|
	|-.-.\.-./.-|
	|.-.-./.\.-.|
	|-.-.\.-./.-|
	|     U     |
	|____% %____|

### Setup 3

`balls:8B-8R; start:B; trace:b|rB|rRB|rRRB`

### Solution 3

	 ___o    ___
	|  .\. ./.  |
	| .-.\./.-. |
	|.-.-.^.-.-.|
	|-.-.\.\.-.-|
	|.-.-.^./.-.|
	|-.-.\./.-.-|
	|.-.-.X.-.-.|
	|-.-.\./.-.-|
	|.-.-.X.-.-.|
	|-.-.\.\.-.-|
	|     U     |
	|____% %____|

