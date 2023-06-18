Entity = { archer = false, fighter = false, mage = false }

function	Entity:new()
	local	obj = obj or {}

	setmetatable(obj, self)
	self.__index = self
	return obj
end

return Entity
