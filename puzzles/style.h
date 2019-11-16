/*
 * Style macros for all graphs
 */

/*
 *
 */
#define FONTNAME    Helvetica
#define FONTCOLOR   black

/*
 *
 */
#define NODE_STYLE          \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=10             \
    shape=circle            \

#define EDGE_STYLE          \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=10             \

#define GRAPH_STYLE         \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=12             \

#define START_STYLE         \
    shape=point             \
    width=0.11              \

/*
 *
 */
#define NEXT_BLUE_BALL      \
	B_bot:w -> B_top:w [    \
		style=dotted        \
		dir=none            \
        color=blue          \
	]                       \

#define NEXT_RED_BALL       \
	R_bot:e -> R_top:e [    \
		style=dotted        \
		dir=none            \
        color=red           \
	]                       \

/*
 *
 */

#define GAME_BOARD                  \
	start [ START_STYLE ]           \
	B_top [                         \
		label="B"                   \
		fontcolor=blue              \
	]                               \
	B_bot [                         \
		label="B"                   \
		fontcolor=blue              \
	]                               \
	R_top [                         \
		label="R"                   \
		fontcolor=red               \
	]                               \
	R_bot [                         \
		label="R"                   \
		fontcolor=red               \
	]                               \
	{rank=same; B_top, R_top}       \
	{rank=same; B_bot, R_bot}       \

// vim:ai:sw=4:ts=4:et:syntax=dot
