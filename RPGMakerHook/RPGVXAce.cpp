#include "pch.h"
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
            "if !defined?(rpgvx_save_without_scripts);def rpgvx_save_without_scripts;$data_scripts = nil;save_data($data_actors, 'Data/Actors.rvdata2');save_data($data_classes, 'Data/Classes.rvdata2');save_data($data_skills, 'Data/Skills.rvdata2');save_data($data_items, 'Data/Items.rvdata2');save_data($data_weapons, 'Data/Weapons.rvdata2');save_data($data_armors, 'Data/Armors.rvdata2');save_data($data_enemies, 'Data/Enemies.rvdata2');save_data($data_troops, 'Data/Troops.rvdata2');save_data($data_states, 'Data/States.rvdata2');save_data($data_animations, 'Data/Animations.rvdata2');save_data($data_tilesets, 'Data/Tilesets.rvdata2');save_data($data_common_events, 'Data/CommonEvents.rvdata2');save_data($data_system, 'Data/System.rvdata2');save_data($data_mapinfos, 'Data/MapInfos.rvdata2');$data_scripts = load_data('Data/Scripts.rvdata2');end;end;rpgvx_save_without_scripts;Win32API.new('user32','MessageBox','lppl','l').call(0,'rpgvx_save_without_scripts called!','RPGVXAce',0)"
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
            Win32API.new('user32', 'MessageBox', 'lppl', 'l').call(0, 'rpgvx_save_without_scripts called!', 'RPGVXAce', 0)
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
        },
        {
            eCommandType::DEFINE_REMOVE_INSTANCE_VARIABLE,
            0x4CB780,
            "def rm_iv(sym);  remove_instance_variable sym unless instance_variable_get(sym).nil?;end;"
            /*
            def rm_iv(sym)
              remove_instance_variable(sym) unless instance_variable_get(sym).nil?
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_MAP,
            0x4CB7D9,
            "class RPG::Map;  def convert_vx;    @tileset_id ||= 1;    @data.resize(@width, @height, 4) if @data.zsize < 4;  end;end;"
            /*
            class RPG::Map
              def convert_vx
                @tileset_id ||= 1
                @data.resize(@width, @height, 4) if @data.zsize < 4
              end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_ACTOR,
            0x4CB851,
            "class RPG::Actor;  def convert_vx;    rm_iv :@exp_basis;    rm_iv :@exp_inflation;    rm_iv :@parameters;    rm_iv :@weapon_id;    rm_iv :@armor1_id;    rm_iv :@armor2_id;    rm_iv :@armor3_id;    rm_iv :@armor4_id;    rm_iv :@two_swords_style;    rm_iv :@fix_equipment;    rm_iv :@auto_battle;    rm_iv :@super_guard;    rm_iv :@pharmacology;    rm_iv :@critical_bonus;    @equips ||= [0,0,0,0,0];    @features ||= [];  end;  def __feature_objects;    [self] + [$data_classes[@class_id]];  end;  def __all_features;    __feature_objects.inject([]) {|result, obj| result + obj.features };  end;  def __features(code);    __all_features.select {|ft| ft.code == code };  end;  def __features_set(code);    __features(code).inject([]) {|result, ft| result |= [ft.data_id] };  end;  def __equip_wtype_ok?(wtype_id);    __features_set(51).include?(wtype_id);  end;  def __equip_atype_ok?(atype_id);    __features_set(52).include?(atype_id);  end;  def __equip_type_fixed?(etype_id);    __features_set(53).include?(etype_id);  end;  def __equip_type_sealed?(etype_id);    __features_set(54).include?(etype_id);  end;  def __equippable?(item);    return false unless item.is_a?(RPG::EquipItem);    return false if __equip_type_sealed?(item.etype_id);    return __equip_wtype_ok?(item.wtype_id) if item.is_a?(RPG::Weapon);    return __equip_atype_ok?(item.atype_id) if item.is_a?(RPG::Armor);    return false;  end;  def __dual_wield?;    __features_set(55).max == 1;  end;  def __weapon_set;    $data_weapons.compact.select do |item|;      __equippable?(item);    end;  end ;  def __armor_set(etype_id);    $data_armors.compact.select do |item|;      item.etype_id == etype_id && __equippable?(item);    end;  end ;  def __weapon_id_set;    __weapon_set.collect {|item| item.id };  end;  def __armor_id_set(etype_id);    __armor_set(etype_id).collect {|item| item.id };  end;end;"
            /*
            class RPG::Actor
              def convert_vx
                rm_iv :@exp_basis
                rm_iv :@exp_inflation
                rm_iv :@parameters
                rm_iv :@weapon_id
                rm_iv :@armor1_id
                rm_iv :@armor2_id
                rm_iv :@armor3_id
                rm_iv :@armor4_id
                rm_iv :@two_swords_style
                rm_iv :@fix_equipment
                rm_iv :@auto_battle
                rm_iv :@super_guard
                rm_iv :@pharmacology
                rm_iv :@critical_bonus
                @equips ||= [0, 0, 0, 0, 0]
                @features ||= []
              end

              def __feature_objects
                [self] + [$data_classes[@class_id]]
              end

              def __all_features
                __feature_objects.inject([]) { |result, obj| result + obj.features }
              end

              def __features(code)
                __all_features.select { |ft| ft.code == code }
              end

              def __features_set(code)
                __features(code).inject([]) { |result, ft| result |= [ft.data_id] }
              end

              def __equip_wtype_ok?(wtype_id)
                __features_set(51).include?(wtype_id)
              end

              def __equip_atype_ok?(atype_id)
                __features_set(52).include?(atype_id)
              end

              def __equip_type_fixed?(etype_id)
                __features_set(53).include?(etype_id)
              end

              def __equip_type_sealed?(etype_id)
                __features_set(54).include?(etype_id)
              end

              def __equippable?(item)
                return false unless item.is_a?(RPG::EquipItem)
                return false if __equip_type_sealed?(item.etype_id)
                return __equip_wtype_ok?(item.wtype_id) if item.is_a?(RPG::Weapon)
                return __equip_atype_ok?(item.atype_id) if item.is_a?(RPG::Armor)
                return false
              end

              def __dual_wield?
                __features_set(55).max == 1
              end

              def __weapon_set
                $data_weapons.compact.select do |item|
                  __equippable?(item)
                end
              end

              def __armor_set(etype_id)
                $data_armors.compact.select do |item|
                  item.etype_id == etype_id && __equippable?(item)
                end
              end

              def __weapon_id_set
                __weapon_set.collect { |item| item.id }
              end

              def __armor_id_set(etype_id)
                __armor_set(etype_id).collect { |item| item.id }
              end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_CLASS,
            0x4CBFA1,
            "class RPG::Class;  def convert_vx;    rm_iv :@exp_basis;    rm_iv :@exp_inflation;    rm_iv :@position;    rm_iv :@weapon_set;    rm_iv :@armor_set;    rm_iv :@element_ranks;    rm_iv :@state_ranks;    rm_iv :@skill_name_valid;    rm_iv :@skill_name;    @exp_params ||= [30,20,30,30];    @features ||= [];    @params ||= Table.new(8,100);  end;end;"
            /*
            class RPG::Class
              def convert_vx
                rm_iv :@exp_basis
                rm_iv :@exp_inflation
                rm_iv :@position
                rm_iv :@weapon_set
                rm_iv :@armor_set
                rm_iv :@element_ranks
                rm_iv :@state_ranks
                rm_iv :@skill_name_valid
                rm_iv :@skill_name
                @exp_params ||= [30, 20, 30, 30]
                @features ||= []
                @params ||= Table.new(8, 100)
              end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_ENEMY,
            0x4CC0FD,
            "class RPG::Enemy;  def convert_vx;    rm_iv :@has_critical;    rm_iv :@levitate;    rm_iv :@element_ranks;    rm_iv :@state_ranks;    rm_iv :@maxhp;    rm_iv :@maxmp;    rm_iv :@atk;    rm_iv :@def;    rm_iv :@spi;    rm_iv :@agi;    rm_iv :@drop_item1;    rm_iv :@drop_item2;    @features ||= [];    @params ||= [100,0,10,10,10,10,10,10];    @drop_items ||= Array.new(3) { RPG::Enemy::DropItem.new };  end;end;"
            /*
            class RPG::Enemy
              def convert_vx
                rm_iv :@has_critical
                rm_iv :@levitate
                rm_iv :@element_ranks
                rm_iv :@state_ranks
                rm_iv :@maxhp
                rm_iv :@maxmp
                rm_iv :@atk
                rm_iv :@def
                rm_iv :@spi
                rm_iv :@agi
                rm_iv :@drop_item1
                rm_iv :@drop_item2
                @features ||= []
                @params ||= [100, 0, 10, 10, 10, 10, 10, 10]
                @drop_items ||= Array.new(3) { RPG::Enemy::DropItem.new }
              end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_SKILL,
            0x4CC298,
            "class RPG::Skill;  def convert_vx;    rm_iv :@hit;    rm_iv :@common_event_id;    rm_iv :@physical_attack;    rm_iv :@base_damage;    rm_iv :@variance;    rm_iv :@atk_f;    rm_iv :@spi_f;    rm_iv :@damage_to_mp;    rm_iv :@absorb_damage;    rm_iv :@ignore_defense;    rm_iv :@element_set;    rm_iv :@plus_state_set;    rm_iv :@minus_state_set;    @stype_id ||= 1;    @tp_cost ||= 0;    @success_rate ||= 100;    @hit_type ||= 0;    @required_wtype_id1 ||= 0;    @required_wtype_id2 ||= 0;    @damage ||= RPG::UsableItem::Damage.new;    @effects ||= [];    @features ||= [];  end;end;"
            /*
            class RPG::Skill
              def convert_vx
                rm_iv :@hit
                rm_iv :@common_event_id
                rm_iv :@physical_attack
                rm_iv :@base_damage
                rm_iv :@variance
                rm_iv :@atk_f
                rm_iv :@spi_f
                rm_iv :@damage_to_mp
                rm_iv :@absorb_damage
                rm_iv :@ignore_defense
                rm_iv :@element_set
                rm_iv :@plus_state_set
                rm_iv :@minus_state_set
                @stype_id ||= 1
                @tp_cost ||= 0
                @success_rate ||= 100
                @hit_type ||= 0
                @required_wtype_id1 ||= 0
                @required_wtype_id2 ||= 0
                @damage ||= RPG::UsableItem::Damage.new
                @effects ||= []
                @features ||= []
              end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_ITEM,
            0x4CC4E0,
            "class RPG::Item;  def convert_vx;    rm_iv :@common_event_id;    rm_iv :@hp_recovery_rate;    rm_iv :@hp_recovery;    rm_iv :@mp_recovery_rate;    rm_iv :@mp_recovery;    rm_iv :@parameter_type;    rm_iv :@parameter_points;    rm_iv :@physical_attack;    rm_iv :@base_damage;    rm_iv :@variance;    rm_iv :@atk_f;    rm_iv :@spi_f;    rm_iv :@damage_to_mp;    rm_iv :@absorb_damage;    rm_iv :@ignore_defense;    rm_iv :@element_set;    rm_iv :@plus_state_set;    rm_iv :@minus_state_set;    @itype_id ||= 1;    @success_rate ||= 100;    @hit_type ||= 0;    @damage ||= RPG::UsableItem::Damage.new;    @effects ||= [];    @features ||= [];  end;end;"
            /*
            class RPG::Item
              def convert_vx
                rm_iv :@common_event_id
                rm_iv :@hp_recovery_rate
                rm_iv :@hp_recovery
                rm_iv :@mp_recovery_rate
                rm_iv :@mp_recovery
                rm_iv :@parameter_type
                rm_iv :@parameter_points
                rm_iv :@physical_attack
                rm_iv :@base_damage
                rm_iv :@variance
                rm_iv :@atk_f
                rm_iv :@spi_f
                rm_iv :@damage_to_mp
                rm_iv :@absorb_damage
                rm_iv :@ignore_defense
                rm_iv :@element_set
                rm_iv :@plus_state_set
                rm_iv :@minus_state_set
                @itype_id ||= 1
                @success_rate ||= 100
                @hit_type ||= 0
                @damage ||= RPG::UsableItem::Damage.new
                @effects ||= []
                @features ||= []
              end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_WEAPON,
            0x4CC76A,
            "class RPG::Weapon;  def convert_vx;    rm_iv :@atk;    rm_iv :@def;    rm_iv :@spi;    rm_iv :@agi;    rm_iv :@hit;    rm_iv :@two_handed;    rm_iv :@fast_attack;    rm_iv :@dual_attack;    rm_iv :@critical_bonus;    rm_iv :@element_set;    rm_iv :@state_set;    @features ||= [];    @params ||= [0] * 8;    @etype_id ||= 0;    @wtype_id ||= 1;  end;end;"
            /*
            class RPG::Weapon
              def convert_vx
                rm_iv :@atk
                rm_iv :@def
                rm_iv :@spi
                rm_iv :@agi
                rm_iv :@hit
                rm_iv :@two_handed
                rm_iv :@fast_attack
                rm_iv :@dual_attack
                rm_iv :@critical_bonus
                rm_iv :@element_set
                rm_iv :@state_set
                @features ||= []
                @params ||= [0] * 8
                @etype_id ||= 0
                @wtype_id ||= 1
              end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_ARMOR,
            0x4CC8CC,
            "class RPG::Armor;  def convert_vx;    rm_iv :@kind;    rm_iv :@atk;    rm_iv :@def;    rm_iv :@spi;    rm_iv :@agi;    rm_iv :@eva;    rm_iv :@prevent_critical;    rm_iv :@half_mp_cost;    rm_iv :@double_exp_gain;    rm_iv :@auto_hp_recover;    rm_iv :@element_set;    rm_iv :@state_set;    @features ||= [];    @params ||= [0] * 8;    @etype_id ||= 1;    @atype_id ||= 1;  end;end;"
            /*
            class RPG::Armor
                def convert_vx
                rm_iv :@kind
                rm_iv :@atk
                rm_iv :@def
                rm_iv :@spi
                rm_iv :@agi
                rm_iv :@eva
                rm_iv :@prevent_critical
                rm_iv :@half_mp_cost
                rm_iv :@double_exp_gain
                rm_iv :@auto_hp_recover
                rm_iv :@element_set
                rm_iv :@state_set
                @features ||= []
                @params ||= [0] * 8
                @etype_id ||= 1
                @atype_id ||= 1
                end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_STATE,
            0x4CCA4A,
            "class RPG::State;  def convert_vx;    rm_iv :@atk_rate;    rm_iv :@def_rate;    rm_iv :@spi_rate;    rm_iv :@agi_rate;    rm_iv :@battle_only;    rm_iv :@relase_by_damage;    rm_iv :@hold_turn;    rm_iv :@auto_release_prob;    rm_iv :@nonresistance;    rm_iv :@offset_by_opposite;    rm_iv :@slip_damage;    rm_iv :@reduce_hit_ratio;    rm_iv :@element_set;    rm_iv :@state_set;    @auto_removal_timing ||= 0;    @min_turns ||= 1;    @max_turns ||= 1;    @chance_by_damage ||= 100;    @steps_to_remove ||= 100;    @features ||= [];  end;end;"
            /*
            class RPG::State
              def convert_vx
                rm_iv :@atk_rate
                rm_iv :@def_rate
                rm_iv :@spi_rate
                rm_iv :@agi_rate
                rm_iv :@battle_only
                rm_iv :@release_by_damage
                rm_iv :@hold_turn
                rm_iv :@auto_release_prob
                rm_iv :@nonresistance
                rm_iv :@offset_by_opposite
                rm_iv :@slip_damage
                rm_iv :@reduce_hit_ratio
                rm_iv :@element_set
                rm_iv :@state_set
                @auto_removal_timing ||= 0
                @min_turns ||= 1
                @max_turns ||= 1
                @chance_by_damage ||= 100
                @steps_to_remove ||= 100
                @features ||= []
              end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_RPG_SYSTEM,
            0x4CCC68,
            "class RPG::System;  def convert_vx;    @window_tone ||= Tone.new(0,0,0);    @skill_types ||= [nil,''];    @weapon_types ||= [nil,''];    @armor_types ||= [nil,''];    @terms ||= Terms.new;  end;end;"
            /*
            class RPG::System
              def convert_vx
                @window_tone ||= Tone.new(0, 0, 0)
                @skill_types ||= [nil, '']
                @weapon_types ||= [nil, '']
                @armor_types ||= [nil, '']
                @terms ||= Terms.new
              end
            end
            */
        },
        {
            eCommandType::DEFINE_CLASS_DUNGEON_GENERATOR,
            0x4CE471,
            "class DungeonGenerator;class DgRect;attr_accessor :x1;attr_accessor :y1;attr_accessor :x2;attr_accessor :y2;def initialize(x1, y1, x2, y2);@x1 = x1;@y1 = y1;@x2 = x2;@y2 = y2;end;end;def random_range(a, b);if a > b;return rand(a - b) + b;elsif a == b;return a;else;return rand(b - a) + a;end;end;def check_h(rect);min_y = [rect.y1, rect.y2].min;max_y = [rect.y1, rect.y2].max;min_x = [rect.x1, rect.x2].min - 1;max_x = [rect.x1, rect.x2].max + 1;for y in min_y .. max_y;for x in min_x .. max_x;if @dungeon[x, y] == 1;return false;end;end;end;return true;end;def check_v(rect);min_y = [rect.y1, rect.y2].min - 3;max_y = [rect.y1, rect.y2].max + 3;min_x = [rect.x1, rect.x2].min;max_x = [rect.x1, rect.x2].max;for y in min_y .. max_y;for x in min_x .. max_x;if @dungeon[x, y] == 1;return false;end;end;end;return true;end;def fill(rect);min_y = [rect.y1, rect.y2].min;max_y = [rect.y1, rect.y2].max;min_x = [rect.x1, rect.x2].min;max_x = [rect.x1, rect.x2].max;for y in min_y .. max_y;for x in min_x .. max_x;@dungeon[x, y] = 1;end;end;end;def split(rect, vertical);if rect.x2 - rect.x1 < rect.y2 - rect.y1;if rect.y2 - rect.y1 < 11 * 2;return [rect];else;a = random_range(rect.y1 + 11, rect.y2 - 11);rect1 = DgRect.new(rect.x1, rect.y1, rect.x2, a);rect2 = DgRect.new(rect.x1, a, rect.x2, rect.y2);s1 = split(rect1, true);s2 = split(rect2, true);if vertical || rand(2) == 0;return [s1, s2].flatten;else;return [s2, s1].flatten;end;end;else;if rect.x2 - rect.x1 < 8 * 2;return [rect];else;a = random_range(rect.x1 + 8, rect.x2 - 8);rect1 = DgRect.new(rect.x1, rect.y1, a, rect.y2);rect2 = DgRect.new(a, rect.y1, rect.x2, rect.y2);s1 = split(rect1, false);s2 = split(rect2, false);if !vertical || rand(2) == 0;return [s1, s2].flatten;else;return [s2, s1].flatten;end;end;end;end;def connect(p1, p2, r1, r2);if p1.y2 == p2.y1;max_x1 = [r1.x1, r2.x1].max;min_x2 = [r1.x2, r2.x2].min;if max_x1 < min_x2 && rand(4) == 0;a = b = random_range(max_x1, min_x2);else;a = random_range(r1.x1, r1.x2);b = random_range(r2.x1, r2.x2);end;rect1 = DgRect.new(a, r1.y2 + 1, a, p1.y2);rect2 = DgRect.new(b, r2.y1 - 1, b, p2.y1);rect3 = DgRect.new(a, p1.y2, b, p2.y1);if check_h(rect1) && check_h(rect2) && check_v(rect3);fill(rect1);fill(rect2);fill(rect3);end;elsif p1.x2 == p2.x1;max_y1 = [r1.y1, r2.y1].max;min_y2 = [r1.y2, r2.y2].min;if max_y1 < min_y2 && rand(4) == 0;a = b = random_range(max_y1, min_y2);else;a = random_range(r1.y1, r1.y2);b = random_range(r2.y1, r2.y2);end;rect1 = DgRect.new(r1.x2 + 1, a, p1.x2, a);rect2 = DgRect.new(r2.x1 - 1, b, p2.x1, b);rect3 = DgRect.new(p1.x2, a, p2.x1, b);if check_v(rect1) && check_v(rect2) && check_v(rect3);fill(rect1);fill(rect2);fill(rect3);end;end;end;def make_corrider(partitions, rooms);connect_list = [];for i in 0 .. partitions.length - 2;connect_list.push([i, i + 1]);end;for i in 0 .. partitions.length - 2;for j in i + 2 .. partitions.length - 1;f1 = (partitions[i].x1 == partitions[j].x2);f2 = (partitions[i].x2 == partitions[j].x1);f3 = (partitions[i].y1 == partitions[j].y2);f4 = (partitions[i].y2 == partitions[j].y1);if f1 || f2 || f3 || f4;connect_list.push([i, j]);end;end;end;connect_list.each do |x|;connect(partitions[x[0]], partitions[x[1]], rooms[x[0]], rooms[x[1]]);connect(partitions[x[1]], partitions[x[0]], rooms[x[1]], rooms[x[0]]);end;end;def generate(type);rect = DgRect.new(6, 3, @dungeon.xsize - 7, @dungeon.ysize - 4);if @dungeon.xsize - 7 < @dungeon.ysize - 4;partitions = split(rect, true);else;partitions = split(rect, false);end;rooms = partitions.collect do |p|;if type == 0;x1 = p.x1 + random_range(2, (p.x2 - p.x1) / 2 - 1);y1 = p.y1 + random_range(4, (p.y2 - p.y1) / 2 - 1);x2 = p.x2 - random_range(2, (p.x2 - p.x1) / 2 - 1);y2 = p.y2 - random_range(4, (p.y2 - p.y1) / 2 - 1);else;x1 = (p.x1 + p.x2) / 2 - 0;y1 = (p.y1 + p.y2) / 2 - 0;x2 = (p.x1 + p.x2) / 2 + 0;y2 = (p.y1 + p.y2) / 2 + 0;end;DgRect.new(x1, y1, x2, y2);end;rooms.each do |room|;fill(room);end;make_corrider(partitions, rooms);end;def execute(map, type, floor, wall1, wall2);map.data = Table.new(map.width, map.height, 4);@dungeon = Table.new(map.width, map.height);generate(type);for y in 0 ... @dungeon.ysize;for x in 0 ... @dungeon.xsize;if @dungeon[x, y] == 1;map.data[x, y, 0] = floor;else;map.data[x, y, 0] = wall1;end;end;end;for y in 2 ... @dungeon.ysize;for x in 0 ... @dungeon.xsize;if @dungeon[x, y] == 1;data1 = map.data[x, y - 1, 0];data2 = map.data[x, y - 2, 0];if data1 == wall1 && data2 == wall1;map.data[x, y - 1, 0] = wall2;map.data[x, y - 2, 0] = wall2;end;end;end;end;end;end;;"
            /*
            class DungeonGenerator
              class DgRect
                attr_accessor :x1
                attr_accessor :y1
                attr_accessor :x2
                attr_accessor :y2

                def initialize(x1, y1, x2, y2)
                  @x1 = x1
                  @y1 = y1
                  @x2 = x2
                  @y2 = y2
                end
              end

              def random_range(a, b)
                if a > b
                  return rand(a - b) + b
                elsif a == b
                  return a
                else
                  return rand(b - a) + a
                end
              end

              def check_h(rect)
                min_y = [rect.y1, rect.y2].min
                max_y = [rect.y1, rect.y2].max
                min_x = [rect.x1, rect.x2].min - 1
                max_x = [rect.x1, rect.x2].max + 1

                for y in min_y .. max_y
                  for x in min_x .. max_x
                    if @dungeon[x, y] == 1
                      return false
                    end
                  end
                end

                return true
              end

              def check_v(rect)
                min_y = [rect.y1, rect.y2].min - 3
                max_y = [rect.y1, rect.y2].max + 3
                min_x = [rect.x1, rect.x2].min
                max_x = [rect.x1, rect.x2].max

                for y in min_y .. max_y
                  for x in min_x .. max_x
                    if @dungeon[x, y] == 1
                      return false
                    end
                  end
                end

                return true
              end

              def fill(rect)
                min_y = [rect.y1, rect.y2].min
                max_y = [rect.y1, rect.y2].max
                min_x = [rect.x1, rect.x2].min
                max_x = [rect.x1, rect.x2].max

                for y in min_y .. max_y
                  for x in min_x .. max_x
                    @dungeon[x, y] = 1
                  end
                end
              end

              def split(rect, vertical)
                if rect.x2 - rect.x1 < rect.y2 - rect.y1
                  if rect.y2 - rect.y1 < 11 * 2
                    return [rect]
                  else
                    a = random_range(rect.y1 + 11, rect.y2 - 11)
                    rect1 = DgRect.new(rect.x1, rect.y1, rect.x2, a)
                    rect2 = DgRect.new(rect.x1, a, rect.x2, rect.y2)
                    s1 = split(rect1, true)
                    s2 = split(rect2, true)

                    if vertical || rand(2) == 0
                      return [s1, s2].flatten
                    else
                      return [s2, s1].flatten
                    end
                  end
                else
                  if rect.x2 - rect.x1 < 8 * 2
                    return [rect]
                  else
                    a = random_range(rect.x1 + 8, rect.x2 - 8)
                    rect1 = DgRect.new(rect.x1, rect.y1, a, rect.y2)
                    rect2 = DgRect.new(a, rect.y1, rect.x2, rect.y2)
                    s1 = split(rect1, false)
                    s2 = split(rect2, false)

                    if !vertical || rand(2) == 0
                      return [s1, s2].flatten
                    else
                      return [s2, s1].flatten
                    end
                  end
                end
              end

              def connect(p1, p2, r1, r2)
                if p1.y2 == p2.y1
                  max_x1 = [r1.x1, r2.x1].max
                  min_x2 = [r1.x2, r2.x2].min

                  if max_x1 < min_x2 && rand(4) == 0
                    a = b = random_range(max_x1, min_x2)
                  else
                    a = random_range(r1.x1, r1.x2)
                    b = random_range(r2.x1, r2.x2)
                  end

                  rect1 = DgRect.new(a, r1.y2 + 1, a, p1.y2)
                  rect2 = DgRect.new(b, r2.y1 - 1, b, p2.y1)
                  rect3 = DgRect.new(a, p1.y2, b, p2.y1)

                  if check_h(rect1) && check_h(rect2) && check_v(rect3)
                    fill(rect1)
                    fill(rect2)
                    fill(rect3)
                  end
                elsif p1.x2 == p2.x1
                  max_y1 = [r1.y1, r2.y1].max
                  min_y2 = [r1.y2, r2.y2].min

                  if max_y1 < min_y2 && rand(4) == 0
                    a = b = random_range(max_y1, min_y2)
                  else
                    a = random_range(r1.y1, r1.y2)
                    b = random_range(r2.y1, r2.y2)
                  end

                  rect1 = DgRect.new(r1.x2 + 1, a, p1.x2, a)
                  rect2 = DgRect.new(r2.x1 - 1, b, p2.x1, b)
                  rect3 = DgRect.new(p1.x2, a, p2.x1, b)

                  if check_v(rect1) && check_v(rect2) && check_v(rect3)
                    fill(rect1)
                    fill(rect2)
                    fill(rect3)
                  end
                end
              end

              def make_corrider(partitions, rooms)
                connect_list = []

                for i in 0 .. partitions.length - 2
                  connect_list.push([i, i + 1])
                end

                for i in 0 .. partitions.length - 2
                  for j in i + 2 .. partitions.length - 1
                    f1 = (partitions[i].x1 == partitions[j].x2)
                    f2 = (partitions[i].x2 == partitions[j].x1)
                    f3 = (partitions[i].y1 == partitions[j].y2)
                    f4 = (partitions[i].y2 == partitions[j].y1)

                    if f1 || f2 || f3 || f4
                      connect_list.push([i, j])
                    end
                  end
                end

                connect_list.each do |x|
                  connect(partitions[x[0]], partitions[x[1]], rooms[x[0]], rooms[x[1]])
                  connect(partitions[x[1]], partitions[x[0]], rooms[x[1]], rooms[x[0]])
                end
              end

              def generate(type)
                rect = DgRect.new(6, 3, @dungeon.xsize - 7, @dungeon.ysize - 4)

                if @dungeon.xsize - 7 < @dungeon.ysize - 4
                  partitions = split(rect, true)
                else
                  partitions = split(rect, false)
                end

                rooms = partitions.collect do |p|
                  if type == 0
                    x1 = p.x1 + random_range(2, (p.x2 - p.x1) / 2 - 1)
                    y1 = p.y1 + random_range(4, (p.y2 - p.y1) / 2 - 1)
                    x2 = p.x2 - random_range(2, (p.x2 - p.x1) / 2 - 1)
                    y2 = p.y2 - random_range(4, (p.y2 - p.y1) / 2 - 1)
                  else
                    x1 = (p.x1 + p.x2) / 2 - 0
                    y1 = (p.y1 + p.y2) / 2 - 0
                    x2 = (p.x1 + p.x2) / 2 + 0
                    y2 = (p.y1 + p.y2) / 2 + 0
                  end

                  DgRect.new(x1, y1, x2, y2)
                end

                rooms.each do |room|
                  fill(room)
                end

                make_corrider(partitions, rooms)
              end

              def execute(map, type, floor, wall1, wall2)
                map.data = Table.new(map.width, map.height, 4)
                @dungeon = Table.new(map.width, map.height)
                generate(type)

                for y in 0 ... @dungeon.ysize
                  for x in 0 ... @dungeon.xsize
                    if @dungeon[x, y] == 1
                      map.data[x, y, 0] = floor
                    else
                      map.data[x, y, 0] = wall1
                    end
                  end
                end

                for y in 2 ... @dungeon.ysize
                  for x in 0 ... @dungeon.xsize
                    if @dungeon[x, y] == 1
                      data1 = map.data[x, y - 1, 0]
                      data2 = map.data[x, y - 2, 0]

                      if data1 == wall1 && data2 == wall1
                        map.data[x, y - 1, 0] = wall2
                        map.data[x, y - 2, 0] = wall2
                      end
                    end
                  end
                end
              end
            end
            */
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION1,
            0x504620,
            "$data_scripts_cur_sel = $data_exit_code / 65536;$data_scripts_top_index = [$data_scripts_cur_sel - 20, 0].max;$data_scripts_cur_id = $data_scripts[$data_scripts_cur_sel][0];cur_line = $data_exit_code % 65536 - 1;first_line = [cur_line - 20, 0].max;$sch00 = {} if $sch00 == nil;$sch00[$data_scripts_cur_id] = [first_line, cur_line, 0];"
            /*
            $data_scripts_cur_sel = $data_exit_code / 65536
            $data_scripts_top_index = [$data_scripts_cur_sel - 20, 0].max
            $data_scripts_cur_id = $data_scripts[$data_scripts_cur_sel][0]
            cur_line = $data_exit_code % 65536 - 1
            first_line = [cur_line - 20, 0].max
            $sch00 = {} if $sch00 == nil
            $sch00[$data_scripts_cur_id] = [first_line, cur_line, 0]
            */
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION2,
            0x505608,
            "$scb00 = deep_copy($data_scripts)"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION3,
            0x50562C,
            "$data_scripts = deep_copy($scb00)"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION4,
            0x505608,
            "$sch00[%d] = [%d,%d,%d]"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION5,
            0x505668,
            "$sch00[%d][2]"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION6,
            0x505688,
            "$sch00[%d][0]"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION7,
            0x505698,
            "@a = $data_scripts[%d]"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION8,
            0x5056B0,
            "$data_scripts[%d][1]"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION9,
            0x5056C8,
            "@a = $data_scripts[%d];begin;  @a[0] = rand(99999999)+1;  f = false;  for b in $data_scripts;    f = true if b != @a and b[0] == @a[0];  end;end while f;$sch00[@a[0]] = [0,0];"
            /*
            @a = $data_scripts[%d]
            begin
              @a[0] = rand(99999999)+1
              f = false
              for b in $data_scripts
                f = true if b != @a and b[0] == @a[0]
              end
            end while f
            $sch00[@a[0]] = [0, 0]
            */
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION10,
            0x505778,
            "$data_scripts_cur_sel"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION11,
            0x505824,
            "$sch00 = {} if $sch00 == nil"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION12,
            0x505844,
            "$data_scripts.size"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION13,
            0x505858,
            "$data_scripts_cur_id = %d"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION14,
            0x505874,
            "$data_scripts_cur_sel = %d"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION15,
            0x505890,
            "$data_scripts_top_index = %d"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION16,
            0x5058C4,
            "$data_scripts[%d,0] = [[1,'','']];"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION17,
            0x505904,
            "@sc"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION18,
            0x505908,
            "@sc = $data_scripts[%d]"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION19,
            0x505928,
            "$data_scripts[%d,0] = [@sc]"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION20,
            0x505944,
            "$data_scripts"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION21,
            0x505960,
            "$grep_result[%d][1]"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION22,
            0x505974,
            "$grep_result[%d][0]"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION23,
            0x505988,
            "$grep_result = [];for i in 0...$data_scripts.size;  section_name = $data_scripts[i][1];  section_text = Zlib::Inflate.inflate($data_scripts[i][2]);  section_text.force_encoding('utf-8');  line_count = 0;  section_text.each_line do |line|;    line_count += 1;    pos2 = 0;    loop do;      pos1 = line.index($grep_pat, pos2);      break if pos1.nil?;      pos2 = pos1 + $grep_str.size;      next if $grep_whole_word && !is_word?(line, pos1, pos2);      s = \"#{section_name} (#{line_count}) : #{line}\";      $grep_result.push([i, line_count-1, s]);      break;    end;  end;end;"
            /*
            $grep_result = []
            for i in 0...$data_scripts.size
              section_name = $data_scripts[i][1]
              section_text = Zlib::Inflate.inflate($data_scripts[i][2])
              section_text.force_encoding('utf-8')
              line_count = 0
              section_text.each_line do |line|
                line_count += 1
                pos2 = 0
                loop do
                  pos1 = line.index($grep_pat, pos2)
                  break if pos1.nil?
                  pos2 = pos1 + $grep_str.size
                  next if $grep_whole_word && !is_word?(line, pos1, pos2)
                  s = "#{section_name} (#{line_count}) : #{line}"
                  $grep_result.push([i, line_count-1, s])
                  break
                end
              end
            end
            */
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION24,
            0x505BC8,
            "$grep_whole_word = false"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION25,
            0x505BE4,
            "$grep_whole_word = true"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION26,
            0x505BFC,
            "$grep_pat = Regexp.new(Regexp.escape($grep_str), true)"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION27,
            0x505C34,
            "$grep_pat = Regexp.new(Regexp.escape($grep_str))"
        },
        {
            eCommandType::DEFINE_SCRIPT_EDITOR_ACTION28,
            0x505C68,
            "$grep_str"
        }
    };
}