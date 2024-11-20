var obj = { 1: 'a', 2: 'b', 3: 'c', 4: 'd' };

console.log(Object.keys(obj));
console.log(Object.values(obj));

for (const [key, value] of Object.entries(obj)) {
  console.log(`${key}: ${value}`);
}
