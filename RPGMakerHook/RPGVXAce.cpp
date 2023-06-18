#include "RPGVXAce.h"

namespace RPGVXAce
{
    CommandInfo gCommands[] =
    {
        // CALL command pointer addresses
        {
            eCommandType::PTR_CALL_RPGVX_LOAD,
            0x11BD7 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGVX_SAVE,
            0x11BF7 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGVX_BATTLE_TEST_SAVE,
            0x11C17 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGVX_BATTLE_TEST_DELETE,
            0x11C37 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGVX_ADJUST1,
            0x11C57 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGVX_ADJUST2,
            0x11C65 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGVX_ADJUST3,
            0x11C73 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGVX_ADJUST4,
            0x11C81 + 1,
            ""
        },
        // DEFINE script addresses
        {
            eCommandType::DEFINE_RPGVX_LOAD,
            0x4CCD2E,
            "def rpgvx_load;$data_actors = nil;$data_classes = nil;$data_skills = nil;$data_items = nil;$data_weapons = nil;$data_armors = nil;$data_enemies = nil;$data_troops = nil;$data_states = nil;$data_animations = nil;$data_tilesets = nil;$data_common_events = nil;$data_system = nil;$data_mapinfos = nil;$data_scripts = nil;$data_actors = load_data('Data/Actors.rvdata2');$data_classes = load_data('Data/Classes.rvdata2');$data_skills = load_data('Data/Skills.rvdata2');$data_items = load_data('Data/Items.rvdata2');$data_weapons = load_data('Data/Weapons.rvdata2');$data_armors = load_data('Data/Armors.rvdata2');$data_enemies = load_data('Data/Enemies.rvdata2');$data_troops = load_data('Data/Troops.rvdata2');$data_states = load_data('Data/States.rvdata2');$data_animations = load_data('Data/Animations.rvdata2');$data_tilesets = load_data('Data/Tilesets.rvdata2');$data_common_events = load_data('Data/CommonEvents.rvdata2');$data_system = load_data('Data/System.rvdata2');$data_mapinfos = load_data('Data/MapInfos.rvdata2');$data_scripts = load_data('Data/Scripts.rvdata2');end;;"
            /*
            def rpgvx_load
              $data_actors = nil
              $data_classes = nil
              $data_skills = nil
              $data_items = nil
              $data_weapons = nil
              $data_armors = nil
              $data_enemies = nil
              $data_troops = nil
              $data_states = nil
              $data_animations = nil
              $data_tilesets = nil
              $data_common_events = nil
              $data_system = nil
              $data_mapinfos = nil
              $data_scripts = nil

              $data_actors = load_data('Data/Actors.rvdata2')
              $data_classes = load_data('Data/Classes.rvdata2')
              $data_skills = load_data('Data/Skills.rvdata2')
              $data_items = load_data('Data/Items.rvdata2')
              $data_weapons = load_data('Data/Weapons.rvdata2')
              $data_armors = load_data('Data/Armors.rvdata2')
              $data_enemies = load_data('Data/Enemies.rvdata2')
              $data_troops = load_data('Data/Troops.rvdata2')
              $data_states = load_data('Data/States.rvdata2')
              $data_animations = load_data('Data/Animations.rvdata2')
              $data_tilesets = load_data('Data/Tilesets.rvdata2')
              $data_common_events = load_data('Data/CommonEvents.rvdata2')
              $data_system = load_data('Data/System.rvdata2')
              $data_mapinfos = load_data('Data/MapInfos.rvdata2')
              $data_scripts = load_data('Data/Scripts.rvdata2')
            end
            */
        },
        {
            eCommandType::DEFINE_RPGVX_SAVE,
            0x4CD164,
            "def rpgvx_save;save_data($data_actors, 'Data/Actors.rvdata2');save_data($data_classes, 'Data/Classes.rvdata2');save_data($data_skills, 'Data/Skills.rvdata2');save_data($data_items, 'Data/Items.rvdata2');save_data($data_weapons, 'Data/Weapons.rvdata2');save_data($data_armors, 'Data/Armors.rvdata2');save_data($data_enemies, 'Data/Enemies.rvdata2');save_data($data_troops, 'Data/Troops.rvdata2');save_data($data_states, 'Data/States.rvdata2');save_data($data_animations, 'Data/Animations.rvdata2');save_data($data_tilesets, 'Data/Tilesets.rvdata2');save_data($data_common_events, 'Data/CommonEvents.rvdata2');save_data($data_system, 'Data/System.rvdata2');save_data($data_mapinfos, 'Data/MapInfos.rvdata2');save_data($data_scripts, 'Data/Scripts.rvdata2');end;;"
            /*
            def rpgvx_save
              save_data($data_actors, 'Data/Actors.rvdata2')
              save_data($data_classes, 'Data/Classes.rvdata2')
              save_data($data_skills, 'Data/Skills.rvdata2')
              save_data($data_items, 'Data/Items.rvdata2')
              save_data($data_weapons, 'Data/Weapons.rvdata2')
              save_data($data_armors, 'Data/Armors.rvdata2')
              save_data($data_enemies, 'Data/Enemies.rvdata2')
              save_data($data_troops, 'Data/Troops.rvdata2')
              save_data($data_states, 'Data/States.rvdata2')
              save_data($data_animations, 'Data/Animations.rvdata2')
              save_data($data_tilesets, 'Data/Tilesets.rvdata2')
              save_data($data_common_events, 'Data/CommonEvents.rvdata2')
              save_data($data_system, 'Data/System.rvdata2')
              save_data($data_mapinfos, 'Data/MapInfos.rvdata2')
              save_data($data_scripts, 'Data/Scripts.rvdata2')
            end
            */
        },
        // CUSTOM Scripts
        {
            eCommandType::DEFINE_AND_CALL_RPGVX_SAVE_WITHOUT_SCRIPTS,
            0x4C766D,
            "if !defined?(rpgvx_save_without_scripts);def rpgvx_save_without_scripts;$data_scripts = nil;save_data($data_actors, 'Data/Actors.rvdata2');save_data($data_classes, 'Data/Classes.rvdata2');save_data($data_skills, 'Data/Skills.rvdata2');save_data($data_items, 'Data/Items.rvdata2');save_data($data_weapons, 'Data/Weapons.rvdata2');save_data($data_armors, 'Data/Armors.rvdata2');save_data($data_enemies, 'Data/Enemies.rvdata2');save_data($data_troops, 'Data/Troops.rvdata2');save_data($data_states, 'Data/States.rvdata2');save_data($data_animations, 'Data/Animations.rvdata2');save_data($data_tilesets, 'Data/Tilesets.rvdata2');save_data($data_common_events, 'Data/CommonEvents.rvdata2');save_data($data_system, 'Data/System.rvdata2');save_data($data_mapinfos, 'Data/MapInfos.rvdata2');$data_scripts = load_data('Data/Scripts.rvdata2');end;end;rpgvx_save_without_scripts;Win32API.new('user32','MessageBox','lppl','l').call(0,'rpgxp_save_without_scripts completed!','',0)"
            /*
            if !defined?(rpgvx_save_without_scripts)
              def rpgvx_save_without_scripts
                $data_scripts = nil
                save_data($data_actors, 'Data/Actors.rvdata2')
                save_data($data_classes, 'Data/Classes.rvdata2')
                save_data($data_skills, 'Data/Skills.rvdata2')
                save_data($data_items, 'Data/Items.rvdata2')
                save_data($data_weapons, 'Data/Weapons.rvdata2')
                save_data($data_armors, 'Data/Armors.rvdata2')
                save_data($data_enemies, 'Data/Enemies.rvdata2')
                save_data($data_troops, 'Data/Troops.rvdata2')
                save_data($data_states, 'Data/States.rvdata2')
                save_data($data_animations, 'Data/Animations.rvdata2')
                save_data($data_tilesets, 'Data/Tilesets.rvdata2')
                save_data($data_common_events, 'Data/CommonEvents.rvdata2')
                save_data($data_system, 'Data/System.rvdata2')
                save_data($data_mapinfos, 'Data/MapInfos.rvdata2')
                $data_scripts = load_data('Data/Scripts.rvdata2')
              end
            end
            rpgvx_save_without_scripts
            Win32API.new('user32', 'MessageBox', 'lppl', 'l').call(0, 'rpgxp_save_without_scripts completed!', '', 0)
            */
        }
    };
}