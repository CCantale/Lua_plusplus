deepcopy = require("deepcopy")

local Component = { 
				ID		=	0,
				list	=	{},

				new		=	function(self, entity_ID)
					local	new_component = deepcopy(self)

					new_component.entity_ID = entity_ID
					table.insert(self.list, new_component) 
					return self.ID
				end
			}

local function	new_component_blueprint(blueprint, list)
	setmetatable(blueprint, { __index = Component })
	blueprint.ID = 2^Component_blueprints.nbr
	blueprint.list = list
	Component_blueprints.nbr = Component_blueprints.nbr + 1
	return blueprint
end


info = {}
physics = {}

Component_blueprints = {}

Component_blueprints.nbr = 0

Component_blueprints.info = new_component_blueprint({ name = "No name", age = 0 }, info)
Component_blueprints.physics = new_component_blueprint({ speed = 0, weight = 0 }, physics)

return Component_blueprints
