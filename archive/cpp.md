## typename
```
template <typename T>
void processContainer() {
    typename T::iterator it = T().begin(); // Specifies that iterator is a type
    while (it != T().end()) {
        // Process elements
        ++it;
    }
}
```

* `virtual ~ISettingsManager() - default` - destructor
