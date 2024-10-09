# 짱 멋진(Sassy) CSS：SCSS

[상세 링크](https://cocoon1787.tistory.com/843)

## Nested Styling

### Pesuedo

```scss
// SCSS
.card {
  padding: 20px;
  background-color: #f1f1f1;
  border-radius: 4px;
  position: relative;

  // Style the ::before pseudo-element within the .card selector
  &:before {
    content: '';
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background-color: rgba(0, 0, 0, 0.1);
    border-radius: 4px;
  }

  // Style the ::after pseudo-element within the .card selector
  &:after {
    content: 'Card Content';
    position: absolute;
    bottom: 10px;
    right: 10px;
    color: #888;
    font-size: 14px;
  }
}
```
