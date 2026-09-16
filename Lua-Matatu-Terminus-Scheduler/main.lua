-- CCS 2105 Programming Languages
-- Group 1: Matatu Terminus Scheduler using Lua Coroutines

local routes = {
    {name = "Rongai", passengers = 0, waiting = 0},
    {name = "Thika", passengers = 0, waiting = 0},
    {name = "Ngong", passengers = 0, waiting = 0},
    {name = "Kitengela", passengers = 0, waiting = 0}
}

local function createRouteCoroutine(route)
    return coroutine.create(function()
        while true do
            local command = coroutine.yield()

            if command == "board" then
                route.passengers = route.passengers + 1
                route.waiting = 0
            elseif command == "wait" then
                route.waiting = route.waiting + 1
            end

            if route.passengers >= 8 or
               (route.waiting > 3 and route.passengers >= 5) then
                print(route.name .. " matatu departing with " .. route.passengers .. " passengers.")
                route.passengers = 0
                route.waiting = 0
            end
        end
    end)
end

local routeCoroutines = {}

for _, route in ipairs(routes) do
    routeCoroutines[route.name] = createRouteCoroutine(route)
end

local function scheduler(totalCycles)
    local currentRoute = 1

    for cycle = 1, totalCycles do
        local route = routes[currentRoute]
        local co = routeCoroutines[route.name]
        local command

        if route.passengers < 5 then
            command = "board"
        else
            command = "wait"
        end

        local success, errorMessage = coroutine.resume(co, command)

        if not success then
            print("Error in " .. route.name .. ": " .. tostring(errorMessage))
        end

        currentRoute = currentRoute + 1
        if currentRoute > #routes then
            currentRoute = 1
        end
    end
end

scheduler(40)

print("\nFinal Route States:")
for _, route in ipairs(routes) do
    print(route.name .. " | Passengers: " .. route.passengers .. " | Waiting: " .. route.waiting)
end
