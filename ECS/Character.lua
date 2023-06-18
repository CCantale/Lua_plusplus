Entity = require("Entity")

Character = Entity:new()
table.insert(Character, name)
table.insert(Character, strength)
table.insert(Character, hp)

function	Character:new(name, strength, hp)
	local	obj = obj or {}

	setmetatable(obj, self)
	self.__index = self
	obj.name = name
	obj.strength = strength
	obj.hp = hp
	return obj
end

return Character
