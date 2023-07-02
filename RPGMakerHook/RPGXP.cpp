#include "pch.h"
#include "RPGXP.h"

namespace RPGXP
{
    CommandInfo gCommands[] =
    {
        // CALL command pointer addresses
        {
            eCommandType::PTR_CALL_RPGXP_LOAD,
            0xAEA7 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGXP_SAVE,
            0xAEC7 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGXP_BATTLE_TEST_SAVE,
            0xAEE7 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGXP_BATTLE_TEST_DELETE,
            0xAF07 + 1,
            ""
        },
        {
            eCommandType::PTR_CALL_RPGXP_ADJUST,
            0xAF27 + 1,
            "",
        },
        // DEFINE script addresses
        {
            eCommandType::DEFINE_RPGXP_LOAD,
            0x17EDC0,
            "def rpgxp_load;$data_actors = nil;$data_classes = nil;$data_skills = nil;$data_items = nil;$data_weapons = nil;$data_armors = nil;$data_enemies = nil;$data_troops = nil;$data_states = nil;$data_animations = nil;$data_tilesets = nil;$data_common_events = nil;$data_system = nil;$data_mapinfos = nil;$data_scripts = nil;$data_actors = load_data('Data/Actors.rxdata');$data_classes = load_data('Data/Classes.rxdata');$data_skills = load_data('Data/Skills.rxdata');$data_items = load_data('Data/Items.rxdata');$data_weapons = load_data('Data/Weapons.rxdata');$data_armors = load_data('Data/Armors.rxdata');$data_enemies = load_data('Data/Enemies.rxdata');$data_troops = load_data('Data/Troops.rxdata');$data_states = load_data('Data/States.rxdata');$data_animations = load_data('Data/Animations.rxdata');$data_tilesets = load_data('Data/Tilesets.rxdata');$data_common_events = load_data('Data/CommonEvents.rxdata');$data_system = load_data('Data/System.rxdata');$data_mapinfos = load_data('Data/MapInfos.rxdata');$data_scripts = load_data('Data/Scripts.rxdata');end;;"
            /*
            def rpgxp_load
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

              $data_actors = load_data('Data/Actors.rxdata')
              $data_classes = load_data('Data/Classes.rxdata')
              $data_skills = load_data('Data/Skills.rxdata')
              $data_items = load_data('Data/Items.rxdata')
              $data_weapons = load_data('Data/Weapons.rxdata')
              $data_armors = load_data('Data/Armors.rxdata')
              $data_enemies = load_data('Data/Enemies.rxdata')
              $data_troops = load_data('Data/Troops.rxdata')
              $data_states = load_data('Data/States.rxdata')
              $data_animations = load_data('Data/Animations.rxdata')
              $data_tilesets = load_data('Data/Tilesets.rxdata')
              $data_common_events = load_data('Data/CommonEvents.rxdata')
              $data_system = load_data('Data/System.rxdata')
              $data_mapinfos = load_data('Data/MapInfos.rxdata')
              $data_scripts = load_data('Data/Scripts.rxdata')
            end
            */
        },
        {
            eCommandType::DEFINE_RPGXP_SAVE,
            0x17F1E7,
            "def rpgxp_save;save_data($data_actors, 'Data/Actors.rxdata');save_data($data_classes, 'Data/Classes.rxdata');save_data($data_skills, 'Data/Skills.rxdata');save_data($data_items, 'Data/Items.rxdata');save_data($data_weapons, 'Data/Weapons.rxdata');save_data($data_armors, 'Data/Armors.rxdata');save_data($data_enemies, 'Data/Enemies.rxdata');save_data($data_troops, 'Data/Troops.rxdata');save_data($data_states, 'Data/States.rxdata');save_data($data_animations, 'Data/Animations.rxdata');save_data($data_tilesets, 'Data/Tilesets.rxdata');save_data($data_common_events, 'Data/CommonEvents.rxdata');save_data($data_system, 'Data/System.rxdata');save_data($data_mapinfos, 'Data/MapInfos.rxdata');save_data($data_scripts, 'Data/Scripts.rxdata');end;;"
            /*
            def rpgxp_save
              save_data($data_actors, 'Data/Actors.rxdata')
              save_data($data_classes, 'Data/Classes.rxdata')
              save_data($data_skills, 'Data/Skills.rxdata')
              save_data($data_items, 'Data/Items.rxdata')
              save_data($data_weapons, 'Data/Weapons.rxdata')
              save_data($data_armors, 'Data/Armors.rxdata')
              save_data($data_enemies, 'Data/Enemies.rxdata')
              save_data($data_troops, 'Data/Troops.rxdata')
              save_data($data_states, 'Data/States.rxdata')
              save_data($data_animations, 'Data/Animations.rxdata')
              save_data($data_tilesets, 'Data/Tilesets.rxdata')
              save_data($data_common_events, 'Data/CommonEvents.rxdata')
              save_data($data_system, 'Data/System.rxdata')
              save_data($data_mapinfos, 'Data/MapInfos.rxdata')
              save_data($data_scripts, 'Data/Scripts.rxdata')
            end
            */
        },
        {
            eCommandType::DEFINE_RPGXP_BATTLE_TEST_SAVE,
            0x17F4D0,
            "def rpgxp_bt_save;save_data($data_actors, 'Data/BT_Actors.rxdata');save_data($data_classes, 'Data/BT_Classes.rxdata');save_data($data_skills, 'Data/BT_Skills.rxdata');save_data($data_items, 'Data/BT_Items.rxdata');save_data($data_weapons, 'Data/BT_Weapons.rxdata');save_data($data_armors, 'Data/BT_Armors.rxdata');save_data($data_enemies, 'Data/BT_Enemies.rxdata');save_data($data_troops, 'Data/BT_Troops.rxdata');save_data($data_states, 'Data/BT_States.rxdata');save_data($data_animations, 'Data/BT_Animations.rxdata');save_data($data_tilesets, 'Data/BT_Tilesets.rxdata');save_data($data_common_events, 'Data/BT_CommonEvents.rxdata');save_data($data_system, 'Data/BT_System.rxdata');end;;"
            /*
            def rpgxp_bt_save
              save_data($data_actors, 'Data/BT_Actors.rxdata')
              save_data($data_classes, 'Data/BT_Classes.rxdata')
              save_data($data_skills, 'Data/BT_Skills.rxdata')
              save_data($data_items, 'Data/BT_Items.rxdata')
              save_data($data_weapons, 'Data/BT_Weapons.rxdata')
              save_data($data_armors, 'Data/BT_Armors.rxdata')
              save_data($data_enemies, 'Data/BT_Enemies.rxdata')
              save_data($data_troops, 'Data/BT_Troops.rxdata')
              save_data($data_states, 'Data/BT_States.rxdata')
              save_data($data_animations, 'Data/BT_Animations.rxdata')
              save_data($data_tilesets, 'Data/BT_Tilesets.rxdata')
              save_data($data_common_events, 'Data/BT_CommonEvents.rxdata')
              save_data($data_system, 'Data/BT_System.rxdata')
            end
            */
        },
        {
            eCommandType::DEFINE_RPGXP_BATTLE_TEST_DELETE,
            0x17F781,
            "def rpgxp_bt_delete;File.delete('Data/BT_Actors.rxdata');File.delete('Data/BT_Classes.rxdata');File.delete('Data/BT_Skills.rxdata');File.delete('Data/BT_Items.rxdata');File.delete('Data/BT_Weapons.rxdata');File.delete('Data/BT_Armors.rxdata');File.delete('Data/BT_Enemies.rxdata');File.delete('Data/BT_Troops.rxdata');File.delete('Data/BT_States.rxdata');File.delete('Data/BT_Animations.rxdata');File.delete('Data/BT_Tilesets.rxdata');File.delete('Data/BT_CommonEvents.rxdata');File.delete('Data/BT_System.rxdata');end;;"
            /*
            def rpgxp_bt_delete
              File.delete('Data/BT_Actors.rxdata')
              File.delete('Data/BT_Classes.rxdata')
              File.delete('Data/BT_Skills.rxdata')
              File.delete('Data/BT_Items.rxdata')
              File.delete('Data/BT_Weapons.rxdata')
              File.delete('Data/BT_Armors.rxdata')
              File.delete('Data/BT_Enemies.rxdata')
              File.delete('Data/BT_Troops.rxdata')
              File.delete('Data/BT_States.rxdata')
              File.delete('Data/BT_Animations.rxdata')
              File.delete('Data/BT_Tilesets.rxdata')
              File.delete('Data/BT_CommonEvents.rxdata')
              File.delete('Data/BT_System.rxdata')
            end
            */
        },
        {
            eCommandType::DEFINE_RPGXP_ADJUST,
            0x17F989,
            "def rpgxp_adjust;for i in 1...$data_actors.size;$data_actors[i].id = i;end;for i in 1...$data_classes.size;$data_classes[i].id = i;end;for i in 1...$data_skills.size;$data_skills[i].id = i;end;for i in 1...$data_items.size;$data_items[i].id = i;end;for i in 1...$data_weapons.size;$data_weapons[i].id = i;end;for i in 1...$data_armors.size;$data_armors[i].id = i;end;for i in 1...$data_enemies.size;$data_enemies[i].id = i;end;for i in 1...$data_troops.size;$data_troops[i].id = i;end;for i in 1...$data_states.size;$data_states[i].id = i;end;for i in 1...$data_animations.size;$data_animations[i].id = i;end;for i in 1...$data_tilesets.size;$data_tilesets[i].id = i;end;for i in 1...$data_common_events.size;$data_common_events[i].id = i;end;for a in $data_actors.compact;if a.class_id >= $data_classes.size;a.class_id = 1;end;ws = $data_classes[a.class_id].weapon_set;as = $data_classes[a.class_id].armor_set;if a.weapon_id >= $data_weapons.size || !ws.include?(a.weapon_id);a.weapon_id = 0;end;if a.armor1_id >= $data_armors.size || !as.include?(a.armor1_id);a.armor1_id = 0;end;if a.armor2_id >= $data_armors.size || !as.include?(a.armor2_id);a.armor2_id = 0;end;if a.armor3_id >= $data_armors.size || !as.include?(a.armor3_id);a.armor3_id = 0;end;if a.armor4_id >= $data_armors.size || !as.include?(a.armor4_id);a.armor4_id = 0;end;if a.armor1_id > 0 && $data_armors[a.armor1_id].kind != 0;a.armor1_id = 0;end;if a.armor2_id > 0 && $data_armors[a.armor2_id].kind != 1;a.armor2_id = 0;end;if a.armor3_id > 0 && $data_armors[a.armor3_id].kind != 2;a.armor3_id = 0;end;if a.armor4_id > 0 && $data_armors[a.armor4_id].kind != 3;a.armor4_id = 0;end;end;for a in $data_classes.compact;a.element_ranks.resize($data_system.elements.size);for i in 1...$data_system.elements.size;if a.element_ranks[i] == 0;a.element_ranks[i] = 3;end;end;a.state_ranks.resize($data_states.size);for i in 1...$data_states.size;if a.state_ranks[i] == 0;a.state_ranks[i] = 3;end;end;for l in a.learnings.clone;if l.skill_id >= $data_skills.size;a.learnings.delete(l);end;end;end;for a in $data_skills.compact;if a.animation1_id >= $data_animations.size;a.animation1_id = 0;end;if a.animation2_id >= $data_animations.size;a.animation2_id = 0;end;for i in a.element_set.clone;if i >= $data_system.elements.size;a.element_set.delete(i);end;end;for i in a.plus_state_set.clone;if i >= $data_states.size;a.plus_state_set.delete(i);end;end;for i in a.minus_state_set.clone;if i >= $data_states.size;a.minus_state_set.delete(i);end;end;end;for a in $data_items.compact;if a.animation1_id >= $data_animations.size;a.animation1_id = 0;end;if a.animation2_id >= $data_animations.size;a.animation2_id = 0;end;for i in a.element_set.clone;if i >= $data_system.elements.size;a.element_set.delete(i);end;end;for i in a.plus_state_set.clone;if i >= $data_states.size;a.plus_state_set.delete(i);end;end;for i in a.minus_state_set.clone;if i >= $data_states.size;a.minus_state_set.delete(i);end;end;end;for a in $data_weapons.compact;if a.animation1_id >= $data_animations.size;a.animation1_id = 0;end;if a.animation2_id >= $data_animations.size;a.animation2_id = 0;end;for i in a.element_set.clone;if i >= $data_system.elements.size;a.element_set.delete(i);end;end;for i in a.plus_state_set.clone;if i >= $data_states.size;a.plus_state_set.delete(i);end;end;for i in a.minus_state_set.clone;if i >= $data_states.size;a.minus_state_set.delete(i);end;end;end;for a in $data_armors.compact;if a.auto_state_id >= $data_states.size;a.auto_state_id = 0;end;state = $data_states[a.auto_state_id];if state != nil and state.zero_hp;a.auto_state_id = 0;end;for i in a.guard_element_set.clone;if i >= $data_system.elements.size;a.guard_element_set.delete(i);end;end;for i in a.guard_state_set.clone;if i >= $data_states.size;a.guard_state_set.delete(i);end;end;end;for a in $data_enemies.compact;if a.animation1_id >= $data_animations.size;a.animation1_id = 0;end;if a.animation2_id >= $data_animations.size;a.animation2_id = 0;end;a.element_ranks.resize($data_system.elements.size);for i in 1...$data_system.elements.size;if a.element_ranks[i] == 0;a.element_ranks[i] = 3;end;end;a.state_ranks.resize($data_states.size);for i in 1...$data_states.size;if a.state_ranks[i] == 0;a.state_ranks[i] = 3;end;end;if a.item_id >= $data_items.size;a.item_id = 0;end;if a.weapon_id >= $data_weapons.size;a.weapon_id = 0;end;if a.armor_id >= $data_armors.size;a.armor_id = 0;end;end;for a in $data_states.compact;if a.animation_id >= $data_animations.size;a.animation_id = 0;end;end;for a in $data_tilesets.compact;for i in 0..7;for j in 0..47;a.terrain_tags[i*48+j] = a.terrain_tags[i*48];end;end;end;for i in $data_system.party_members.clone;if i >= $data_actors.size;$data_system.party_members.delete(i);end;end;for a in $data_system.test_battlers.clone;act = $data_actors[a.actor_id];if act == nil;  $data_system.test_battlers.delete(a);  continue;end;cla = $data_classes[act.class_id];continue if cla == nil;ws = cla.weapon_set;as = cla.armor_set;if a.weapon_id >= $data_weapons.size || !ws.include?(a.weapon_id);a.weapon_id = 0;end;if a.armor1_id >= $data_armors.size || !as.include?(a.armor1_id);a.armor1_id = 0;end;if a.armor2_id >= $data_armors.size || !as.include?(a.armor2_id);a.armor2_id = 0;end;if a.armor3_id >= $data_armors.size || !as.include?(a.armor3_id);a.armor3_id = 0;end;if a.armor4_id >= $data_armors.size || !as.include?(a.armor4_id);a.armor4_id = 0;end;if a.armor1_id > 0 && $data_armors[a.armor1_id].kind != 0;a.armor1_id = 0;end;if a.armor2_id > 0 && $data_armors[a.armor2_id].kind != 1;a.armor2_id = 0;end;if a.armor3_id > 0 && $data_armors[a.armor3_id].kind != 2;a.armor3_id = 0;end;if a.armor4_id > 0 && $data_armors[a.armor4_id].kind != 3;a.armor4_id = 0;end;end;end;;"
            /*
            def rpgxp_adjust
              for i in 1...$data_actors.size
                $data_actors[i].id = i
              end
              for i in 1...$data_classes.size
                $data_classes[i].id= i
              end
              for i in 1...$data_skills.size
                $data_skills[i].id = i
              end
              for i in 1...$data_items.size
                $data_items[i].id = i
              end
              for i in 1...$data_weapons.size
                $data_weapons[i].id =i
              end
              for i in 1...$data_armors.size
                $data_armors[i].id= i
              end
              for i in 1...$data_enemies.size
                $data_enemies[i].id = i
              end
              for i in 1...$data_troops.size
                $data_troops[i].id =i
              end
              for i in 1...$data_states.size
                $data_states[i].id= i
              end
              for i in 1...$data_animations.size
                $data_animations[i].id = i
              end
              for i in 1...$data_tilesets.size
                $data_tilesets[i].id= i
              end
              for i in 1...$data_common_events.size
                $data_common_events[i].id= i
              end
              for a in $data_actors.compact
                if a.class_id >= $data_classes.size
                  a.class_id = 1
                end
                ws = $data_classes[a.class_id].weapon_set
                as = $data_classes[a.class_id].armor_set
                if a.weapon_id >= $data_weapons.size ||!ws.include?(a.weapon_id)
                  a.weapon_id =0
                end
                if a.armor1_id >=$data_armors.size || !as.include?(a.armor1_id)
                  a.armor1_id = 0
                end
                if a.armor2_id >= $data_armors.size || !as.include?(a.armor2_id)
                  a.armor2_id= 0
                end
                if a.armor3_id >= $data_armors.size || !as.include?(a.armor3_id)
                  a.armor3_id = 0
                end
                if a.armor4_id >= $data_armors.size || !as.include?(a.armor4_id)
                  a.armor4_id = 0
                end
                if a.armor1_id > 0 && $data_armors[a.armor1_id].kind != 0
                  a.armor1_id= 0
                end
                if a.armor2_id > 0 && $data_armors[a.armor2_id].kind !=1
                  a.armor2_id =0
                end
                if a.armor3_id > 0 && $data_armors[a.armor3_id].kind != 2
                  a.armor3_id = 0
                end
                if a.armor4_id > 0 && $data_armors[a.armor4_id].kind != 3
                  a.armor4_id = 0
                end
              end

              for a in $data_classes.compact
                a.element_ranks.resize($data_system.elements.size)
                for i in 1...$data_system.elements.size
                  if a.element_ranks[i] == 0
                    a.element_ranks[i] = 3
                  end
                end
                a.state_ranks.resize($data_states.size)
                for i in 1...$data_states.size
                  if a.state_ranks[i] ==0
                    a.state_ranks[i] = 3
                  end
                end
                for l in a.learnings.clone
                  if l.skill_id >= $data_skills.size
                    a.learnings.delete(l)
                  end
                end
              end
              for a in $data_skills.compact
                if a.animation1_id >= $data_animations.size
                  a.animation1_id = 0
                end
                if a.animation2_id >= $data_animations.size
                  a.animation2_id = 0
                end
                for i in a.element_set.clone
                  if i >= $data_system.elements.size
                    a.element_set.delete(i)
                  end
                end
                for i in a.plus_state_set.clone
                  if i >= $data_states.size
                    a.plus_state_set.delete(i)
                  end
                end
                for i in a.minus_state_set.clone
                  if i>= $data_states.size
                    a.minus_state_set.delete(i)
                  end
                end
              end
              for a in $data_items.compact
                if a.animation1_id >=$data_animations.size
                  a.animation1_id =0
                end
                if a.animation2_id >= $data_animations.size
                  a.animation2_id = 0
                end
                for i in a.element_set.clone
                  if i >= $data_system.elements.size
                    a.element_set.delete(i)
                  end
                end
                for i in a.plus_state_set.clone
                  if i >= $data_states.size
                    a.plus_state_set.delete(i)
                  end
                end
                for i in a.minus_state_set.clone
                  if i >=$data_states.size
                    a.minus_state_set.delete(i)
                  end
                end
              end
              for a in $data_weapons.compact
                if a.animation1_id >= $data_animations.size
                  a.animation1_id = 0
                end
                if a.animation2_id>= $data_animations.size
                  a.animation2_id = 0
                end
                for i in a.element_set.clone
                  if i >= $data_system.elements.size
                    a.element_set.delete(i)
                  end
                end
                for i in a.plus_state_set.clone
                  if i >= $data_states.size
                    a.plus_state_set.delete(i)
                  end
                end
                for i in a.minus_state_set.clone
                  if i >= $data_states.size
                    a.minus_state_set.delete(i)
                  end
                end
              end
              for a in $data_armors.compact
                if a.auto_state_id >= $data_states.size
                  a.auto_state_id = 0
                end
                state = $data_states[a.auto_state_id]
                if state != nil and state.zero_hp
                  a.auto_state_id = 0
                end
                for i in a.guard_element_set.clone
                  if i >= $data_system.elements.size
                    a.guard_element_set.delete(i)
                  end
                end
                for i in a.guard_state_set.clone
                  if i >= $data_states.size
                    a.guard_state_set.delete(i)
                  end
                end
              end
              for a in $data_enemies.compact
                if a.animation1_id >= $data_animations.size
                  a.animation1_id = 0
                end
                if a.animation2_id >= $data_animations.size
                a.animation2_id = 0
                end
                a.element_ranks.resize($data_system.elements.size)
                for i in 1...$data_system.elements.size
                  if a.element_ranks[i] == 0
                    a.element_ranks[i] = 3
                  end
                end
                a.state_ranks.resize($data_states.size)
                for i in 1...$data_states.size
                  if a.state_ranks[i] ==0
                    a.state_ranks[i] = 3
                  end
                end
                if a.item_id >= $data_items.size
                  a.item_id = 0
                end
                if a.weapon_id >= $data_weapons.size
                  a.weapon_id = 0
                end
                if a.armor_id >= $data_armors.size
                  a.armor_id = 0
                end
              end
              for a in $data_states.compact
                if a.animation_id >=$data_animations.size
                  a.animation_id = 0
                end
              end
              for a in $data_tilesets.compact
                for i in 0..7
                  for j in 0..47
                    a.terrain_tags[i*48+j] = a.terrain_tags[i*48]
                  end
                end
              end
              for i in $data_system.party_members.clone
                if i >= $data_actors.size
                  $data_system.party_members.delete(i)
                end
              end
              for a in $data_system.test_battlers.clone
                act = $data_actors[a.actor_id]
                if act == nil
                  $data_system.test_battlers.delete(a)
                  continue
                end
                cla = $data_classes[act.class_id]
                continue if cla == nil
                ws = cla.weapon_set
                as = cla.armor_set
                if a.weapon_id >= $data_weapons.size || !ws.include?(a.weapon_id)
                  a.weapon_id = 0
                end
                if a.armor1_id >= $data_armors.size|| !as.include?(a.armor1_id)
                  a.armor1_id = 0
                end
                if a.armor2_id >= $data_armors.size ||!as.include?(a.armor2_id)
                  a.armor2_id =0
                end
                if a.armor3_id >= $data_armors.size || !as.include?(a.armor3_id)
                  a.armor3_id = 0
                end
                if a.armor4_id >= $data_armors.size || !as.include?(a.armor4_id)
                  a.armor4_id= 0
                end
                if a.armor1_id > 0 && $data_armors[a.armor1_id].kind != 0
                  a.armor1_id =0
                end
                if a.armor2_id > 0 && $data_armors[a.armor2_id].kind != 1
                  a.armor2_id = 0
                end
                if a.armor3_id > 0 && $data_armors[a.armor3_id].kind != 2
                  a.armor3_id = 0
                end
                if a.armor4_id > 0 && $data_armors[a.armor4_id].kind != 3
                  a.armor4_id= 0
                end
              end
            end
            */
        },
        {
            eCommandType::DEFINE_DEEP_COPY,
            0x180FF1,
            "def deep_copy(obj);Marshal.load(Marshal.dump(obj));end;"
            /*
            def deep_copy(obj)
              Marshal.load(Marshal.dump(obj))
            end
            */
        },
        // CUSTOM Scripts
        {
            eCommandType::DEFINE_AND_CALL_RPGXP_SAVE_WITHOUT_SCRIPTS,
            0x2E0,
            "if !defined?(rpgxp_save_without_scripts);def rpgxp_save_without_scripts;$data_scripts = nil;save_data($data_actors, 'Data/Actors.rxdata');save_data($data_classes, 'Data/Classes.rxdata');save_data($data_skills, 'Data/Skills.rxdata');save_data($data_items, 'Data/Items.rxdata');save_data($data_weapons, 'Data/Weapons.rxdata');save_data($data_armors, 'Data/Armors.rxdata');save_data($data_enemies, 'Data/Enemies.rxdata');save_data($data_troops, 'Data/Troops.rxdata');save_data($data_states, 'Data/States.rxdata');save_data($data_animations, 'Data/Animations.rxdata');save_data($data_tilesets, 'Data/Tilesets.rxdata');save_data($data_common_events, 'Data/CommonEvents.rxdata');save_data($data_system, 'Data/System.rxdata');save_data($data_mapinfos, 'Data/MapInfos.rxdata');$data_scripts = load_data('Data/Scripts.rxdata');end;Win32API.new('user32', 'MessageBox', 'lppl', 'l').call(0, 'rpgxp_save_without_scripts hooking succeeded!\nWhen you save the project, the \\'Scripts.rxdata\\' file is no longer saved, but it is re-opened.', 'RPGMakerHook', 0x00000040);end;rpgxp_save_without_scripts;"
            /*
            if !defined?(rpgxp_save_without_scripts)
              def rpgxp_save_without_scripts
                $data_scripts = nil
                save_data($data_actors, 'Data/Actors.rxdata')
                save_data($data_classes, 'Data/Classes.rxdata')
                save_data($data_skills, 'Data/Skills.rxdata')
                save_data($data_items, 'Data/Items.rxdata')
                save_data($data_weapons, 'Data/Weapons.rxdata')
                save_data($data_armors, 'Data/Armors.rxdata')
                save_data($data_enemies, 'Data/Enemies.rxdata')
                save_data($data_troops, 'Data/Troops.rxdata')
                save_data($data_states, 'Data/States.rxdata')
                save_data($data_animations, 'Data/Animations.rxdata')
                save_data($data_tilesets, 'Data/Tilesets.rxdata')
                save_data($data_common_events, 'Data/CommonEvents.rxdata')
                save_data($data_system, 'Data/System.rxdata')
                save_data($data_mapinfos, 'Data/MapInfos.rxdata')
                $data_scripts = load_data('Data/Scripts.rxdata')
              end
            end
            rpgxp_save_without_scripts
            Win32API.new('user32', 'MessageBox', 'lppl', 'l').call(0, 'rpgxp_save_without_scripts \'Scripts.rxdata\' called!', 'RPGXP', 0)
            */
        }
    };
}