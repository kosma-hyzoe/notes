## Lua

```lua
local nums = { 1, 2, 3 }
table.insert(nums, 4)
for i = 1, #nums do --[['#' - number of colors ]] end

local dict = {
  ["key1"] = 1,
  ["key2"] = 2
}
print(dict["key1"])
for k,d in pairs(dict) do end
dict["key1"] = nil
dict["key2"] = 3

math.abs(-1)
math.ceil(1.2) -- 2
math.floor(1.2) -- 1

require("mymodlue")
```
