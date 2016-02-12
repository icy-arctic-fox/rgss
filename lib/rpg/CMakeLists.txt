cmake_minimum_required(VERSION 3.0)

# Ruby files can't be included in any order,
# since they have dependencies on each other,
# so a working ordering is specified here.
set(RB_FILES
        map.rb
        map/encounter.rb
        map_info.rb
        event.rb
        event/page.rb
        event/page/condition.rb
        event/page/graphic.rb
        event_command.rb
        move_route.rb
        move_command.rb
        base_item.rb
        actor.rb
        class.rb
        class/learning.rb
        usable_item.rb
        skill.rb
        item.rb
        equip_item.rb
        weapon.rb
        armor.rb
        enemy.rb
        state.rb
        base_item/feature.rb
        usable_item/damage.rb
        usable_item/effect.rb
        enemy/drop_item.rb
        enemy/action.rb
        troop.rb
        troop/member.rb
        troop/page.rb
        troop/page/condition.rb
        animation.rb
        animation/frame.rb
        animation/timing.rb
        tileset.rb
        common_event.rb
        system.rb
        system/vehicle.rb
        system/terms.rb
        system/test_battler.rb
        audio_file.rb
        bgm.rb
        bgs.rb
        me.rb
        se.rb
        )

# Add each Ruby script as a resource,
# and populate the variables that will build the header file.
foreach(RB_FILE ${RB_FILES})
    ADD_RUBY_SCRIPT(${RB_FILE} SYMBOL)
    set(SRC_FILES ${SRC_FILES} ${RB_FILE}.c)
    set(EXTERNS "${EXTERNS}extern const char ${SYMBOL}[];\n")
    set(SYMBOLS "${SYMBOLS}    ${SYMBOL},\n")
endforeach(RB_FILE)

# Create a header file that defines the symbols for the scripts.
configure_file(symbols.h.in symbols.h)

# Create a static library containing nothing but the Ruby script resources.
add_library(rgss_rpg STATIC ${SRC_FILES})
