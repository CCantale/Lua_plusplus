deepcopy = require("deepcopy")

components_nbr = 0

Component = { 
				ID		=	0,
				list	=	{},

				new		=	function(self, entity_ID)
					local	new_component = deepcopy(self)

					new_component.entity_ID = entity_ID
					table.insert(self.list, new_component) 
					return self.ID
				end
			}

function	new_component_blueprint(blueprint, list)
	setmetatable(blueprint, { __index = Component })
	blueprint.ID = 2^components_nbr
	blueprint.list = list
	components_nbr = components_nbr + 1
	return blueprint
end

info = {}
physics = {}

Components_list = {
					info = new_component_blueprint({ name = "No name", age = 0}, info),
					physics = new_component_blueprint({ speed = 0, weight = 0}, physics)
				}

function	Components_list:nbr()
	local	nbr = 0

	for _, _ in pairs(self) do
		nbr = nbr + 1
	end
	return nbr - 1 -- remove this same function from the count, since it is technically inside the table as well
end

return Components_list
