Entity = require("Entity")

me = Entity.new("info", "physics", "hello")
Entity.add_components(me, "physics") -- fuck! What if I add it twice?? Should check the signature first..., even in new()
print(me)
print(Entities[me])

print(info[me].name)
print(physics[me].speed) -- it's gonna be better with a getter

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


