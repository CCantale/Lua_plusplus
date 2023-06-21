Components = require("Components")

Entities = {} -- This is gonna be an array of signatures

Entities_freeIDs = {}

function	get_newID()
	if #Entities_freeIDs == 0 then
		return #Entities + 1
	else
		local	new_ID = Entities_freeIDs[#Entities_freeIDs]

		table.remove(Entities_freeIDs, #Entities_freeIDs)
		return new_ID
	end
end

Entity	= {
				new = function(...)
					if Components:nbr() == 0 then
						print("There's no components yet") -- I might wanna add a make_component() function later on
					end
					local	components_toadd = { ... }
					local	new_ID = 0
					local	new_signature = 0

					for _, v in ipairs(components_toadd) do
						if Components[v] then
							if new_ID == 0 then
								new_ID = get_newID()
							end
							Components[v]:new(new_ID)
							new_signature = new_signature | Components[v].ID
						else
							print(string.format("Error. \"%s\" no such component", v))
						end
					end
					if new_ID > 0 then
						Entities[#Entities + 1] = tonumber(new_signature)
						return new_ID
					else
						return nil
					end
				end,

				add_components = function(entity_ID, ...)
					if not Entities[entity_ID] then
						print(string.format("Error: \"%s\" no such entity"))
						return
					end
					if not Entities[entity_ID] then
						return
					end
					local	components = { ... }
					local	new_signature = Entities[entity_ID]

					for i, v in ipairs(components) do
						if Components[v] then
							Components[v]:new(entity_ID)
							new_signature = new_signature | Components[v].ID
						else
							print(string.format("Error. \"%s\" no such component", v))
						end
					end
					Entities[entity_ID] = new_signature
				end
		}

return Entity
