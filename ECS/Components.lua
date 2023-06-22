deepcopy = require("deepcopy")
Lists = require("Component_lists")

local Component = {}

Component.ID = 0
Component.comp_name = "No name"
Component.new = function(self, entity_ID)
					local	new_component = deepcopy(self)

					new_component.entity_ID = entity_ID
					Lists[self.comp_name][entity_ID] = new_component
					return self.ID
				end

Component_blueprints = {}
Component_blueprints.nbr = 0

local function	new_component_blueprint(blueprint, name)
	setmetatable(blueprint, { __index = Component })
	blueprint.ID = 2^Component_blueprints.nbr
	blueprint.comp_name = name
	Component_blueprints[name] = blueprint
	Lists[name] = {}
	Component_blueprints.nbr = Component_blueprints.nbr + 1
	return blueprint
end

new_component_blueprint({ name = "No name", age = 0 }, "info")
new_component_blueprint({ speed = 0, weight = 0 }, "physics")

return Component_blueprints
