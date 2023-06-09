#ifndef __RPGXP_H__
#define __RPGXP_H__

namespace RPGXP
{
    enum eCommandType {
        PTR_CALL_RPGXP_LOAD,
        PTR_CALL_RPGXP_SAVE,
        PTR_CALL_RPGXP_BATTLE_TEST_SAVE,
        PTR_CALL_RPGXP_BATTLE_TEST_DELETE,
        PTR_CALL_RPGXP_ADJUST,

        DEFINE_RPGXP_LOAD,
        DEFINE_RPGXP_SAVE,
        DEFINE_RPGXP_BATTLE_TEST_SAVE,
        DEFINE_RPGXP_BATTLE_TEST_DELETE,
        DEFINE_RPGXP_ADJUST,
        DEFINE_DEEP_COPY,

        DEFINE_AND_CALL_RPGXP_SAVE_WITHOUT_SCRIPTS,

        SIZE
    };

    struct CommandInfo
    {
        eCommandType Type;
        int Offset;
        char Scripts[6144];
    };
}

#endif // __RPGXP_H__