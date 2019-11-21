## Challenge #30: Overflow

### Objective

Count the blue balls in register A. If there are more than 7, gear bit OV must flip right (and stay right) to indicate the overflow.

### Setup

`init:*B-0R; start:B; trace:*B`

### Solution

	 ___o    ___
	|  .<. .-.  |
	| .\.\.-.-. |
	|.-.<./.-.-.|
	|-.\.\.-.-.-|
	|.-.<./.-.-.|
	|-*{./.-.-.-|OV
	|.{./.-.-.-.|
	|\./.-.-.-.-|
	|./.-.-.-.-.|
	|\.-.-.-.-.-|
	|     -     |
	|____% %____|

