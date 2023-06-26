local Entity = require("Entity")

me = Entity.new("info")
Entity.add_components(me, "physics")
print(me)
print(Entity.signatures[me])

Entity.set_attribute(me, "info", "name", "Claudio")
Entity.set_attribute(me, "physics", "speed", "100")
print(Entity.get_attribute(me, "info", "name"), Entity.get_attribute(me, "physics", "speed"), Entity.get_attribute(me, "hello", "halo"))

Entity.remove_component(me, "info")
Entity.add_components(me, "info")
print(Entity.get_attribute(me, "info", "name"))

--					TO DEVELOP
--
--Entity:update_component(me, "info", "Claudio", 29)
--
--[[function	make_goblin()
--		goblin = Entity.new("info")
--
--		Entity:update_component(goblin, "info", "Goblin", "unknown")
--		return goblin
--	end
]]
