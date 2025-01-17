/*****************************************************************************
 * Copyright (c) 2014-2019 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "FormatCodes.h"

#include "../common.h"
#include "Localisation.h"

#include <iterator>

#pragma region Format codes

struct format_code_token
{
    uint32_t code;
    const char* token;
};

// clang-format off
static constexpr const format_code_token format_code_tokens[] = {
    { FORMAT_MOVE_X,                    "MOVE_X"                },
    { FORMAT_ADJUST_PALETTE,            "ADJUST_PALETTE"        },
    { FORMAT_NEWLINE,                   "NEWLINE"               },
    { FORMAT_NEWLINE_SMALLER,           "NEWLINE_SMALLER"       },
    { FORMAT_TINYFONT,                  "TINYFONT"              },
    { FORMAT_BIGFONT,                   "BIGFONT"               },
    { FORMAT_MEDIUMFONT,                "MEDIUMFONT"            },
    { FORMAT_SMALLFONT,                 "SMALLFONT"             },
    { FORMAT_OUTLINE,                   "OUTLINE"               },
    { FORMAT_OUTLINE_OFF,               "OUTLINE_OFF"           },
    { FORMAT_WINDOW_COLOUR_1,           "WINDOW_COLOUR_1"       },
    { FORMAT_WINDOW_COLOUR_2,           "WINDOW_COLOUR_2"       },
    { FORMAT_WINDOW_COLOUR_3,           "WINDOW_COLOUR_3"       },
    { FORMAT_NEWLINE_X_Y,               "NEWLINE_X_Y"           },
    { FORMAT_INLINE_SPRITE,             "INLINE_SPRITE"         },
    { FORMAT_COMMA32,                   "COMMA32"               },
    { FORMAT_INT32,                     "INT32"                 },
    { FORMAT_COMMA2DP32,                "COMMA2DP32"            },
    { FORMAT_COMMA16,                   "COMMA16"               },
    { FORMAT_UINT16,                    "UINT16"                },
    { FORMAT_CURRENCY2DP,               "CURRENCY2DP"           },
    { FORMAT_CURRENCY,                  "CURRENCY"              },
    { FORMAT_STRINGID,                  "STRINGID"              },
    { FORMAT_STRINGID2,                 "STRINGID2"             },
    { FORMAT_STRING,                    "STRING"                },
    { FORMAT_MONTHYEAR,                 "MONTHYEAR"             },
    { FORMAT_MONTH,                     "MONTH"                 },
    { FORMAT_VELOCITY,                  "VELOCITY"              },
    { FORMAT_POP16,                     "POP16"                 },
    { FORMAT_PUSH16,                    "PUSH16"                },
    { FORMAT_DURATION,                  "DURATION"              },
    { FORMAT_REALTIME,                  "REALTIME"              },
    { FORMAT_LENGTH,                    "LENGTH"                },
    { FORMAT_SPRITE,                    "SPRITE"                },
    { FORMAT_BLACK,                     "BLACK"                 },
    { FORMAT_GREY,                      "GREY"                  },
    { FORMAT_WHITE,                     "WHITE"                 },
    { FORMAT_RED,                       "RED"                   },
    { FORMAT_GREEN,                     "GREEN"                 },
    { FORMAT_YELLOW,                    "YELLOW"                },
    { FORMAT_TOPAZ,                     "TOPAZ"                 },
    { FORMAT_CELADON,                   "CELADON"               },
    { FORMAT_BABYBLUE,                  "BABYBLUE"              },
    { FORMAT_PALELAVENDER,              "PALELAVENDER"          },
    { FORMAT_PALEGOLD,                  "PALEGOLD"              },
    { FORMAT_LIGHTPINK,                 "LIGHTPINK"             },
    { FORMAT_PEARLAQUA,                 "PEARLAQUA"             },
    { FORMAT_PALESILVER,                "PALESILVER"            },
    { FORMAT_COMMA1DP16,                "COMMA1DP16"            }
};
// clang-format on

uint32_t format_get_code(const char* token)
{
    for (uint32_t i = 0; i < std::size(format_code_tokens); i++)
    {
        if (_strcmpi(token, format_code_tokens[i].token) == 0)
            return format_code_tokens[i].code;
    }
    return 0;
}

const char* format_get_token(uint32_t code)
{
    for (uint32_t i = 0; i < std::size(format_code_tokens); i++)
    {
        if (code == format_code_tokens[i].code)
            return format_code_tokens[i].token;
    }
    return nullptr;
}

//bool utf8_should_use_sprite_for_codepoint(int32_t codepoint)
bool utf8_should_use_sprite_for_codepoint(char32_t codepoint)
{
    switch (codepoint)
    {
        case UnicodeChar::up:
        case UnicodeChar::down:
        case UnicodeChar::leftguillemet:
        case UnicodeChar::tick:
        case UnicodeChar::cross:
        case UnicodeChar::right:
        case UnicodeChar::rightguillemet:
        case UnicodeChar::small_up:
        case UnicodeChar::small_down:
        case UnicodeChar::left:
        case UnicodeChar::quote_open:
        case UnicodeChar::quote_close:
        case UnicodeChar::german_quote_open:
        case UnicodeChar::plus:
        case UnicodeChar::minus:
            return true;
        default:
            return false;
    }
}

#pragma endregion
