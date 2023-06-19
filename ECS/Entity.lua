Entity = {
			archer = false,
			fighter = false,
			mage = false
		}

function	Entity:new(newentity)
	local	obj = newentity or {}

	setmetatable(obj, self)
	self.__index = self
	return obj
end

function	Entity:add_components(...)
	local	components = { ... }

	for _, v in ipairs(components) do
		if self[v] == false then
			self[v] = true
		elseif not self[v] then
			print(string.format("Error: \"%s\" is not a component. Cannot add to entity %s.", v, self.name))
		end
	end
end

return Entity
