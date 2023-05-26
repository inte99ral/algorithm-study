

const example = (function() {
  let instance;

  function setInstance() {
    return {
      data: 'data',
      setData: (data) => { this.data = data },
      getData: () => { return this.data },
    };
  }

  return {
    getInstance: function() {
      if(instance === undefined) instance = setInstance();
      return instance;
    }
  }
})();

const example1 = example.getInstance();
const example2 = example.getInstance();

console.log(example1.getData());
example1.setData('new Data');

console.log(example2.getData());
console.log(example1 == example2);
console.log(example1 === example2);