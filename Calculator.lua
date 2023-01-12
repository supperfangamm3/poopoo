Calculator = {}
Calculator.__index = Calculator

function Calculator:new()
  local self = setmetatable({}, Calculator)
  self.result = 0
  return self
end

function Calculator:add(n)
  self.result = self.result + n
end

function Calculator:substract(n)
  self.result = self.result - n
end

function Calculator:multiply(n)
  self.result = self.result * n
end

function Calculator:divide(n)
  self.result = self.result / n
end

function Calculator:clear()
  self.result = 0
end

function Calculator:getResult()
  return self.result
end

calc = Calculator:new()

calc:add()
calc:substract()
calc:multiply()
calc:divide()

print(calc:getResult())
