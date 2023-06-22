Entity = require("Entity")
Comp_lists = require("Component_lists")

me = Entity.new("info", "hello", "info")
Entity.add_components(me, "physics", "info")
print(me)
print(Entity.signatures[me])

Comp_lists.info[me].name = "Claudio"
print(Comp_lists.info[me].name)

print(Comp_lists.physics[me].speed) -- it's gonna be better with a getter


--					TO DEVELOP
--
--Entity.set(me, "name", "Claudio")
--Entity.get(me, "name")
--Entity:update_component(me, "info", "Claudio", 29)
--
--[[function	make_goblin()
--		goblin = Entity.new("info")
--
--		Entity:update_component(goblin, "info", "Goblin", "unknown")
--		return goblin
--	end
]]


