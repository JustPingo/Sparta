function love.load() {
  -- Config
  local neuronAmountPerRow = 10
  local outputs = { } -- Array of functions
  local inputs = { } -- Array of getters

  local neurons = { }
  local neuronAmountPerColumn = table.len(outputs)
  for i = 1, neuronAmountPerRow do
    neurons[i] = { }
    for k = 1, neuronAmountPerColumn do
      neurons[i][k] = randomWeights(neuronAmountPerColumn)
    end
  end
}

local function randomWeights(amount) {
  result = { }
  
  return result
}

function love.update() {
  
}
