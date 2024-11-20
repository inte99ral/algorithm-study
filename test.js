// fetch('https://jsonplaceholder.typicode.com/posts/1')
//   .then((response) => response.json())
//   .then((data) => console.log(data));

fetch('data.json')
  .then((response) => response.json())
  .then((data) => console.log(data))
  .catch((error) => {
    console.log('FAILED' + error);
  });
