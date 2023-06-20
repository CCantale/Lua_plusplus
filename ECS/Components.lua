components_nbr = 0

Components_list = {}

Component = { signature = 0, list = {}, content = {}}

function	Component:new(new_component, id, content) -- no!! This gets called not only once, but every time you need to add a new actual component!!
	local	obj = new_component or {}

	setmetatable(obj, self)
	self._index = self
	obj.signature = 2^components_nbr
	table.insert(new_component.list, content)
end


info = { list = {} }
Component:new(info, { name = "No name", id = 0})



return Components_list
