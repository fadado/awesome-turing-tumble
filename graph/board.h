/*
 * Turing Tumble graphs
 */

/* Logic constants */
#define $false   0
#define $true    1

/* Show graph label? */
#ifndef ShowGraphLabel
#   define ShowGraphLabel $false
#endif

/* Show objective description? */
#ifndef ShowObjective
#   define ShowObjective $false
#endif

/* Show blue/red up lines? */
#ifndef ShowBackBoardEdges
#   define ShowBackBoardEdges $true
#endif

/*
 * Fonts, colors, etc.
 */
#define FONTNAME        Helvetica
#define FONTNAME_BOLD   "Helvetica-Bold"
#define FONTCOLOR       black

#define BITCOLOR        deepskyblue
#define BITSIZE         20

#if 0
#   define BITRIGHT     "⬈"  // north est arrow: U+2B08
#   define BITLEFT      "⬉"  // north west up arrow: U+2B09
#   define BITUNDEF     "⬆"  // upwards arrow: U+2B06
#else
#   define BITRIGHT     ">"  // ASCII alternatives
#   define BITLEFT      "<"
#   define BITUNDEF     "^"
#endif

/*
 * Styles
 */
#define NODE_STYLE          \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=12             \
    shape=circle            \
    fixedsize=true          \

#define EDGE_STYLE          \
    fontname=FONTNAME       \
    fontcolor=FONTCOLOR     \
    fontsize=10             \

#define GRAPH_STYLE         \
    fontname=FONTNAME_BOLD  \
    fontcolor=FONTCOLOR     \
    fontsize=12             \
    labelloc=t              \

#define START_STYLE         \
    shape=point             \
    width=0.11              \

#define OBJECTIVE_STYLE     \
    shape=plaintext         \
    fontsize=10             \
    fontname=Times          \
    fixedsize=false         \

#define BIT_STYLE           \
    shape=diamond           \
    fontcolor=BITCOLOR      \
    fontsize=BITSIZE        \

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

#define BOARD_BACK_BLUE_EDGE    \
    B_bot:w -> B_top:w [        \
        style=dotted            \
        dir=none                \
        color=blue              \
    ]

#define BOARD_BACK_RED_EDGE     \
    R_bot:e -> R_top:e [        \
        style=dotted            \
        dir=none                \
        color=red               \
    ]                           \

#if ShowBackBoardEdges

#define GAME_BOARD_EDGES    \
    BOARD_BACK_BLUE_EDGE    \
    BOARD_BACK_RED_EDGE     \
    B_bot -> R_bot [style=invis]

#else

#define GAME_BOARD_EDGES    \
    B_bot -> R_bot [style=invis]

#endif

/*
 * Labels
 */
#define $text(...)  < <table border="0" cellpadding="0" cellspacing="0">__VA_ARGS__</table> >
#define $line(...)  <tr><td align="left">__VA_ARGS__</td></tr>

// vim:ai:sw=4:ts=4:et:syntax=dot
