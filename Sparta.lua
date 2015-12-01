-- Config
local neuronAmountPerRow = 10
local maxWeight = 100
local outputs = { } -- Array of functions
local inputs = { } -- Array of getters

function love.load()

  local neurons = { }
  local neuronAmountPerColumn = table.len(outputs)
  for i = 1, neuronAmountPerRow do
    neurons[i] = { }
    for k = 1, neuronAmountPerColumn do
      neurons[i][k] = randomWeights(neuronAmountPerColumn)
    end
  end

  

end

local function randomWeights(amount)
  result = { }
  for i = 1, amount do
    result[i] = math.random(0, maxWeight)
  end
  return result
end

function love.update()
  
end

function love.draw()
  
end
