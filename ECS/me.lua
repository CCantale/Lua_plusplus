Character = require("Character")

me = Character:new("me", 100, 200)
me.mage = true
print(string.format("Character.mage = %s\n", Character.mage))
print(string.format("me.mage = %s\n", me.mage))

Entity.mage = true
print(string.format("Character.mage = %s\n", Character.mage))

