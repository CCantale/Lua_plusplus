Components_list = require("Components")

entities_nbr = 0

Entity = { id = 0, signature = 0 }

Entities_list = {}
Entities_freeids = {}

function	Entity:new(new_entity)
	local	obj = new_entity or {}
	
	entities_nbr = entities_nbr + 1
	setmetatable(obj, self)
	self.__index = self
	if #Entities_freeids then
		obj.id = Entities_freeids[#Entities_freeids]
	else
		obj.id = entities_nbr
	end
	obj.signature = 0
	Entities_list[obj.id] = obj.signature -- maybe I'll have to update it every time. dunno
	return obj
end

function	Entity:add_components(...)
	local	components = { ... }

	for i, v in ipairs(components) do
		Components_list(v):add(self.id)
		self.signature = self.signature | Components_list(v).signature
	end
end

return Entity
