#ifndef __RPGVXACE_H__
#define __RPGVXACE_H__

namespace RPGVXAce
{
    enum eCommandType {
        PTR_CALL_RPGVX_LOAD,
        PTR_CALL_RPGVX_SAVE,
        PTR_CALL_RPGVX_BATTLE_TEST_SAVE,
        PTR_CALL_RPGVX_BATTLE_TEST_DELETE,
        PTR_CALL_RPGVX_ADJUST1,
        PTR_CALL_RPGVX_ADJUST2,
        PTR_CALL_RPGVX_ADJUST3,
        PTR_CALL_RPGVX_ADJUST4,

        DEFINE_RPGVX_LOAD,
        DEFINE_RPGVX_SAVE,

        DEFINE_AND_CALL_RPGVX_SAVE_WITHOUT_SCRIPTS,

        SIZE
    };

    struct CommandInfo
    {
        eCommandType Type;
        int Offset;
        char Scripts[6144];
    };
}

#endif // __RPGVXACE_H__