local Lists = {}

Lists.is_component = function(self, component)
	for k, _ in pairs(self) do
		if k == component then
			return true
		end
	end
	print(string.format("Error: is_component(): \"%s\": no such component", component))
	return false
end

return Lists
