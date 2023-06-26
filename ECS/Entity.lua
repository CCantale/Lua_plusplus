local Components = require("Components")
local Component_lists = require("Component_lists")
local Entity	= {}

local function	get_newID()
	if #Entity.freeIDs == 0 then
		return #Entity.signatures + 1
	else
		local	new_ID = Entity.freeIDs[#Entity.freeIDs]

		table.remove(Entity.freeIDs, #Entity.freeIDs)
		return new_ID
	end
end

Entity.signatures = {}

Entity.freeIDs = {}

Entity.has_component = function(entity, component)
	if Component_lists:is_component(component) and Entity.signatures[entity] & Components[component].ID > 0 then
		return true
	else
		print(string.format("Error: Entity.has_component(): Entity %d has no \"%s\" component assigned to it", entity, component))
		return false
	end
end

Entity.new = function(...)
	local	components_toadd = { ... }
	local	new_ID = get_newID()
	local	new_signature = 0

	if Components.nbr == 0 then
		print("There's no components yet") -- I might wanna add a make_component() function later on
	end
	for _, v in ipairs(components_toadd) do
		if Components[v] and new_signature & Components[v].ID == 0 then
			Components[v]:new(new_ID)
			new_signature = new_signature | Components[v].ID
		elseif not Components[v] then
			print(string.format("Error: \"%s\" no such component", v))
		else
			print(string.format("Error: Component \"%s\" was declared twice in the instatiation of entity \"%d\"", v, new_ID))
		end
	end
	if new_signature > 0 then
		Entity.signatures[#Entity.signatures + 1] = tonumber(new_signature)
		return new_ID
	else
		return nil
	end
end

Entity.add_components = function(entity, ...)
	if not Entity.signatures[entity] then
		print(string.format("Error: \"%s\" no such entity"))
		return
	end
	if not Entity.signatures[entity] then
		return
	end
	local	components = { ... }
	local	new_signature = Entity.signatures[entity]

	for i, v in ipairs(components) do
		if Components[v] then 
			Components[v]:new(entity)
			new_signature = new_signature | Components[v].ID
		elseif not Components[v] then
			print(string.format("Error: \"%s\" no such component", v))
		else
			print(string.format("Error: Entity \"%d\" already has component \"%s\"", entity, v))
		end
	end
	Entity.signatures[entity] = new_signature
end

Entity.remove_component = function(entity, component)
	if Entity.has_component(entity, component) then
		Component_lists[component][entity] = nil
		Entity.signatures[entity] = Entity.signatures[entity] ~ Components[component].ID
	end
end

Entity.get_attribute = function(entity, component, attribute)
	if Entity.has_component(entity, component) and Components[component]:has_attribute(attribute) then
		return Component_lists[component][entity][attribute]
	end
end

Entity.set_attribute = function(entity, component, attribute, new_content)
	if Entity.has_component(entity, component) and Components[component]:has_attribute(attribute) then
		Component_lists[component][entity][attribute] = new_content
	end
end

return Entity
