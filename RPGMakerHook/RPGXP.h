#ifndef __RPGXP_H__
#define __RPGXP_H__

namespace RPGXP
{
    enum class CommandType {
        CALL_RPGXP_LOAD,
        CALL_RPGXP_SAVE,
        CALL_RPGXP_BATTLE_TEST_SAVE,
        CALL_RPGXP_BATTLE_TEST_DELETE,
        CALL_RPGXP_ADJUST,

        DEFINITION_RPGXP_LOAD,
        DEFINITION_RPGXP_SAVE,
        DEFINITION_RPGXP_BATTLE_TEST_SAVE,
        DEFINITION_RPGXP_BATTLE_TEST_DELETE,
        DEFINITION_RPGXP_ADJUST,
        DEFINITION_DEEP_COPY,

        SIZE
    };

    struct CommandInfo
    {
        CommandType Type;
        int Offset;
        char Scripts[6144];
    };
}

#endif // __RPGXP_H__