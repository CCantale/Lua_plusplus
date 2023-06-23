local Entity = require("Entity")

me = Entity.new("info")
Entity.add_components(me, "physics")
print(me)
print(Entity.signatures[me])

Entity.set(me, "info", "name", "Claudio")
Entity.set(me, "physics", "speed", "100")
print(Entity.get(me, "info", "name"), Entity.get(me, "physics", "speed"), Entity.get(me, "hello", "halo"))


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
