local Components = require("Components")
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

Entity.add_components = function(entity_ID, ...)
	if not Entity.signatures[entity_ID] then
		print(string.format("Error: \"%s\" no such entity"))
		return
	end
	if not Entity.signatures[entity_ID] then
		return
	end
	local	components = { ... }
	local	new_signature = Entity.signatures[entity_ID]

	for i, v in ipairs(components) do
		if Components[v] and Entity.signatures[entity_ID] & Components[v].ID == 0 then
			Components[v]:new(entity_ID)
			new_signature = new_signature | Components[v].ID
		elseif not Components[v] then
			print(string.format("Error: \"%s\" no such component", v))
		else
			print(string.format("Error: Entity \"%d\" already has component \"%s\"", entity_ID, v))
		end
	end
	Entity.signatures[entity_ID] = new_signature
end

return Entity
