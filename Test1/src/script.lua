package.path = package.path .. ";../?.lua"
values = require("../background_color")

color = { r = values.r, g = values.g, b = values.b, a = values.a }

function	get_backgroundcolor()
	return color.r, color.g, color.b, color.a
end
