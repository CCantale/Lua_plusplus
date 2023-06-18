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

ccantale = Character:new("ccantale", 100, 200)
ccantale.mage = true
print(string.format("Character.mage = %s\n", Character.mage))
print(string.format("ccantale.mage = %s\n", ccantale.mage))

Entity.mage = true
print(string.format("Character.mage = %s\n", Character.mage))

