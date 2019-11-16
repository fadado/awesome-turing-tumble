/*
 * Turing Tumble graphs
 */

/*
 * Fonts, colors, etc.
 */
#define FONTNAME    Helvetica
#define FONTCOLOR   black

/*
 * Styles
 */
#define NODE_STYLE          \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=12             \
    shape=circle            \

#define EDGE_STYLE          \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=10             \

#define GRAPH_STYLE         \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=12             \
    labelloc=t              \

#define START_STYLE         \
    shape=point             \
    width=0.11              \

/*
 * Game Board
 */
#define GAME_BOARD_NODES        \
    start [ START_STYLE ]       \
    B_top [                     \
        label="B"               \
        fontcolor=blue          \
    ]                           \
    B_bot [                     \
        label="B"               \
        fontcolor=blue          \
    ]                           \
    R_top [                     \
        label="R"               \
        fontcolor=red           \
    ]                           \
    R_bot [                     \
        label="R"               \
        fontcolor=red           \
    ]                           \
    {rank=same; B_top, R_top}   \
    {rank=same; B_bot, R_bot}   \

#define GAME_BOARD_EDGES    \
    B_bot:w -> B_top:w [    \
        style=dotted        \
        dir=none            \
        color=blue          \
    ]                       \
    R_bot:e -> R_top:e [    \
        style=dotted        \
        dir=none            \
        color=red           \
    ]                       \
    B_bot -> R_bot [style=invis]

// vim:ai:sw=4:ts=4:et:syntax=dot
