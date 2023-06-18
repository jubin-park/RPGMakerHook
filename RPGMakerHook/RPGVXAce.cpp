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
        {
            eCommandType::DEFINE_RPGVX_BATTLE_TEST_SAVE,
            0x4CD45C,
            "def rpgvx_bt_save;save_data($data_actors, 'Data/BT_Actors.rvdata2');save_data($data_classes, 'Data/BT_Classes.rvdata2');save_data($data_skills, 'Data/BT_Skills.rvdata2');save_data($data_items, 'Data/BT_Items.rvdata2');save_data($data_weapons, 'Data/BT_Weapons.rvdata2');save_data($data_armors, 'Data/BT_Armors.rvdata2');save_data($data_enemies, 'Data/BT_Enemies.rvdata2');save_data($data_troops, 'Data/BT_Troops.rvdata2');save_data($data_states, 'Data/BT_States.rvdata2');save_data($data_animations, 'Data/BT_Animations.rvdata2');save_data($data_tilesets, 'Data/BT_Tilesets.rvdata2');save_data($data_common_events, 'Data/BT_CommonEvents.rvdata2');save_data($data_system, 'Data/BT_System.rvdata2');end;;",
            /*
            def rpgvx_bt_save
              save_data($data_actors, 'Data/BT_Actors.rvdata2')
              save_data($data_classes, 'Data/BT_Classes.rvdata2')
              save_data($data_skills, 'Data/BT_Skills.rvdata2')
              save_data($data_items, 'Data/BT_Items.rvdata2')
              save_data($data_weapons, 'Data/BT_Weapons.rvdata2')
              save_data($data_armors, 'Data/BT_Armors.rvdata2')
              save_data($data_enemies, 'Data/BT_Enemies.rvdata2')
              save_data($data_troops, 'Data/BT_Troops.rvdata2')
              save_data($data_states, 'Data/BT_States.rvdata2')
              save_data($data_animations, 'Data/BT_Animations.rvdata2')
              save_data($data_tilesets, 'Data/BT_Tilesets.rvdata2')
              save_data($data_common_events, 'Data/BT_CommonEvents.rvdata2')
              save_data($data_system, 'Data/BT_System.rvdata2')
            end
            */
        },
        {
            eCommandType::DEFINE_RPGVX_BATTLE_TEST_DELETE,
            0x4CD71A,
            "def rpgvx_bt_delete;File.delete('Data/BT_Actors.rvdata2');File.delete('Data/BT_Classes.rvdata2');File.delete('Data/BT_Skills.rvdata2');File.delete('Data/BT_Items.rvdata2');File.delete('Data/BT_Weapons.rvdata2');File.delete('Data/BT_Armors.rvdata2');File.delete('Data/BT_Enemies.rvdata2');File.delete('Data/BT_Troops.rvdata2');File.delete('Data/BT_States.rvdata2');File.delete('Data/BT_Animations.rvdata2');File.delete('Data/BT_Tilesets.rvdata2');File.delete('Data/BT_CommonEvents.rvdata2');File.delete('Data/BT_System.rvdata2');end;;"
            /*
            def rpgvx_bt_delete
              File.delete('Data/BT_Actors.rvdata2')
              File.delete('Data/BT_Classes.rvdata2')
              File.delete('Data/BT_Skills.rvdata2')
              File.delete('Data/BT_Items.rvdata2')
              File.delete('Data/BT_Weapons.rvdata2')
              File.delete('Data/BT_Armors.rvdata2')
              File.delete('Data/BT_Enemies.rvdata2')
              File.delete('Data/BT_Troops.rvdata2')
              File.delete('Data/BT_States.rvdata2')
              File.delete('Data/BT_Animations.rvdata2')
              File.delete('Data/BT_Tilesets.rvdata2')
              File.delete('Data/BT_CommonEvents.rvdata2')
              File.delete('Data/BT_System.rvdata2')
            end
            */
        },
        {
            eCommandType::DEFINE_RPGVX_ADJUST1,
            0x4CD92F,
            "def rpgvx_adjust1;for i in 1...$data_actors.size;$data_actors[i].id = i;end;for i in 1...$data_classes.size;$data_classes[i].id = i;end;for i in 1...$data_skills.size;$data_skills[i].id = i;end;for i in 1...$data_items.size;$data_items[i].id = i;end;for i in 1...$data_weapons.size;$data_weapons[i].id = i;end;for i in 1...$data_armors.size;$data_armors[i].id = i;end;for i in 1...$data_enemies.size;$data_enemies[i].id = i;end;for i in 1...$data_troops.size;$data_troops[i].id = i;end;for i in 1...$data_states.size;$data_states[i].id = i;end;for i in 1...$data_animations.size;$data_animations[i].id = i;end;for i in 1...$data_tilesets.size;$data_tilesets[i].id = i;end;for i in 1...$data_common_events.size;$data_common_events[i].id = i;end;end;;"
            /*
            def rpgvx_adjust1
              for i in 1...$data_actors.size
                $data_actors[i].id = i
              end
              for i in 1...$data_classes.size
                $data_classes[i].id = i
              end
              for i in 1...$data_skills.size
                $data_skills[i].id = i
              end
              for i in 1...$data_items.size
                $data_items[i].id = i
              end
              for i in 1...$data_weapons.size
                $data_weapons[i].id = i
              end
              for i in 1...$data_armors.size
                $data_armors[i].id = i
              end
              for i in 1...$data_enemies.size
                $data_enemies[i].id = i
              end
              for i in 1...$data_troops.size
                $data_troops[i].id = i
              end
              for i in 1...$data_states.size
                $data_states[i].id = i
              end
              for i in 1...$data_animations.size
                $data_animations[i].id = i
              end
              for i in 1...$data_tilesets.size
                $data_tilesets[i].id = i
              end
              for i in 1...$data_common_events.size
                $data_common_events[i].id = i
              end
            end
            */
        },
        {
            eCommandType::DEFINE_RPGVX_ADJUST2,
            0x4CDC1C,
            "def rpgvx_adjust2;for a in $data_actors.compact;if a.class_id >= $data_classes.size;a.class_id = 1;end;a.convert_vx;end;for a in $data_classes.compact;for l in a.learnings.clone;if l.skill_id >= $data_skills.size;a.learnings.delete(l);end;end;a.convert_vx;end;end;;"
            /*
            def rpgvx_adjust2
              for a in $data_actors.compact
                if a.class_id >= $data_classes.size
                  a.class_id = 1
                end
                a.convert_vx
              end
              for a in $data_classes.compact
                for l in a.learnings.clone
                  if l.skill_id >= $data_skills.size
                    a.learnings.delete(l)
                  end
                end
                a.convert_vx
              end
            end
            */
        },
        {
            eCommandType::DEFINE_RPGVX_ADJUST3,
            0x4CDD25,
            "def rpgvx_adjust3;for a in $data_skills.compact;if a.animation_id >= $data_animations.size;a.animation_id = 0;end;a.convert_vx;end;for a in $data_items.compact;if a.animation_id >= $data_animations.size;a.animation_id = 0;end;a.convert_vx;end;for a in $data_weapons.compact;if a.animation_id >= $data_animations.size;a.animation_id = 0;end;a.convert_vx;end;for a in $data_armors.compact;a.convert_vx;end;end;;"
            /*
            def rpgvx_adjust3
              for a in $data_skills.compact
                if a.animation_id >= $data_animations.size
                  a.animation_id = 0
                end
                a.convert_vx
              end
              for a in $data_items.compact
                if a.animation_id >= $data_animations.size
                  a.animation_id = 0
                end
                a.convert_vx
              end
              for a in $data_weapons.compact
                if a.animation_id >= $data_animations.size
                  a.animation_id = 0
                end
                a.convert_vx
              end
              for a in $data_armors.compact
                a.convert_vx
              end
            end
            */
        },
        {
            eCommandType::DEFINE_RPGVX_ADJUST4,
            0x4CDEBE,
            "def rpgvx_adjust4;for a in $data_enemies.compact;a.convert_vx;end;for a in $data_states.compact;a.convert_vx;end;$data_system.convert_vx;for i in $data_system.party_members.clone;if i >= $data_actors.size;$data_system.party_members.delete(i);end;end;for a in $data_system.test_battlers.clone;act = $data_actors[a.actor_id];if act == nil;  $data_system.test_battlers.delete(a);  next;end;end;end;;"
            /*
            def rpgvx_adjust4
              for a in $data_enemies.compact
                a.convert_vx
              end
              for a in $data_states.compact
                a.convert_vx
              end
              $data_system.convert_vx
              for i in $data_system.party_members.clone
                if i >= $data_actors.size
                  $data_system.party_members.delete(i)
                end
              end
              for a in $data_system.test_battlers.clone
                act = $data_actors[a.actor_id]
                if act == nil
                  $data_system.test_battlers.delete(a)
                  next
                end
              end
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
        },
        {
            eCommandType::DEFINE_DEEP_COPY,
            0x4CE04A,
            "def deep_copy(obj);Marshal.load(Marshal.dump(obj));end;;"
            /*
            def deep_copy(obj)
              Marshal.load(Marshal.dump(obj))
            end
            */
        },
        {
            eCommandType::DEFINE_POSITION_BASE,
            0x4CE082,
            "def position_base(n);case n;when 0; return $data_system;when 1; return $data_system.boat;when 2; return $data_system.ship;when 3; return $data_system.airship;end;return nil;end;;"
            /*
            def position_base(n)
              case n
              when 0
                return $data_system
              when 1
                return $data_system.boat
              when 2
                return $data_system.ship
              when 3
                return $data_system.airship
              end
              return nil
            end
            */
        },
        {
            eCommandType::DEFINE_IS_WORD,
            0x4CE134,
            "def is_word?(line, pos1, pos2);  word_chars = '@_?!$0123456789';  word_chars += 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';  word_chars += 'abcdefghijklmnopqrstuvwxyz';  word_chars.force_encoding('utf-8');  c1 = pos1 == 0 ? nil : line[pos1 - 1];  c2 = line[pos1];  c3 = line[pos2 - 1];  c4 = line[pos2];  cc1 = cc2 = cc3 = cc4 = 0;  cc1 = c1.chr.unpack('C')[0] if c1;  cc2 = c2.chr.unpack('C')[0] if c2;  cc3 = c3.chr.unpack('C')[0] if c3;  cc4 = c4.chr.unpack('C')[0] if c4;  return false if cc2 == 0x20 || cc3 == 0x20;  if cc1 != 0x00 && cc1 != 0x20;    k1 = word_chars.include?(c1) || cc1 >= 0x80;    k2 = word_chars.include?(c2) || cc2 >= 0x80;    return false if k1 == k2;  end;  if cc4 != 0x00 && cc4 != 0x20 && cc4 != 0x0d;    k3 = word_chars.include?(c3);    k4 = word_chars.include?(c4);    return false if k3 == k4;  end;  true;end;;"
            /*
            def is_word?(line, pos1, pos2)
              word_chars = '@_?!$0123456789'
              word_chars += 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
              word_chars += 'abcdefghijklmnopqrstuvwxyz'
              word_chars.force_encoding('utf-8')
              c1 = pos1 == 0 ? nil : line[pos1 - 1]
              c2 = line[pos1]
              c3 = line[pos2 - 1]
              c4 = line[pos2]
              cc1 = cc2 = cc3 = cc4 = 0
              cc1 = c1.chr.unpack('C')[0] if c1
              cc2 = c2.chr.unpack('C')[0] if c2
              cc3 = c3.chr.unpack('C')[0] if c3
              cc4 = c4.chr.unpack('C')[0] if c4
              return false if cc2 == 0x20 || cc3 == 0x20
              if cc1 != 0x00 && cc1 != 0x20
                k1 = word_chars.include?(c1) || cc1 >= 0x80
                k2 = word_chars.include?(c2) || cc2 >= 0x80
                return false if k1 == k2
              end
              if cc4 != 0x00 && cc4 != 0x20 && cc4 != 0x0d
                k3 = word_chars.include?(c3)
                k4 = word_chars.include?(c4)
                return false if k3 == k4
              end
              true
            end
            */
        }
    };
}