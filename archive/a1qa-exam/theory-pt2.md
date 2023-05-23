# Theory notes part 2

## Programming Language constructs

### Casting

Ternary operator
```
condition ? returnIfTrue : returnIfFalse;
String variable = condition ? returnIfTrue : returnIfFalse;
```


"*Type casting is when you assign a value of one primitive data type to another type.*"

Widening type casting can be done automatically
```
nt myInt = 9;
double myDouble = myInt;
```

Narrowing type casting can not
```
double myDouble = 9.78d;
int myInt = (int) myDouble;
```

### Overloading

```Java
class A {
    public void add(int a, int b) {
        System.out.println(a + b);
    }
    public void add(int a, int b, int c) {
        System.out.println(a + b + c);
    }
}
```

### Overriding

```Java
class B {
    public void print() {
        System.out.println("From Class B");
    }
}
class C extends B {
	// must be at least as accessible
	@Override
    public void print() {
        System.out.println("From Class C");
    }
}
```

### Initialisation

"setting up an object's initial state when it is first created." you can initialize them via
assignment (`int a = 5;`) or class constructors.

initializer blocks are which are blocks of code that are executed when an object is created. These blocks are used to
initialize variables that cannot be initialized through constructors or assignment.

```java
class Person {
	public static void main(String[] args) {
		Person p = new Person();
	}
    
	public String name;
	{
        Scanner scanner = new Scanner(System.in);
		System.out.println("Name: ");
        name = scanner.nextLine();
	}
}
```

### Data types

* byte: 1 byte (127)
* short 2 bytes (32_762)
* int: 4 bytes  (> 2_100_000_000)
* long: 8 bytes (9 * 10^18)
* float: 4 bytes (6-7 decimal digits)
* double: 8 bytes (15 decimal digits)
* boolean: 1 bit
* char: 2 bytes

* Reference data types:
* String: a sequence of characters
* Object: the superclass of all classes
* Array: a container for holding multiple values of a single type

### OOP

final classes can't be subclassed.

Composition is a way of creating complex objects by combining simple objects,
as opposed to inheritance which creates a new object based on an existing one.
More flexible anf modular than OOP, yet still capable of encapsulation.

class is a blueprint for creating an object (a data structure).

`Object` methods:

* toString()
* getClass()
* equals(Object obj)
* hashCode()
* clone()
* finalize() - perform cleanup activities before being discarded
* notify() / notifyAll() - wake up threads
* wait()

### Reflection

* .getDeclaredMethods(), .getDeclaredFields() - all
* .getMethods(), .getFields() - public only

### String

* length()
* toUpperCase() / toLowerCase()
* indexOf()
* matches(String regex)
* replace(), replaceFirst(), replaceAll()
* split(String regex)
* substring(int beginIndex) / (int beginIndex int endIndex)

### Lists

you can remove ArrayList elements without knowing its index:

```
arratlistOfIntegers.remove(Integer.valueOf(3));
arratlistOfStrings.remove(String.valueOf("foobar"));
```

linked list:

```
ll.add("foo");
ll.addFirst("bar");
ll.addLast("foobar");
```

array lists are optimized for fast access by index, while linked lists are optimized for fast insertion and deletion
operations.

### Misc

* declaration - specifying name, type and POSSIBLY value
* `public void foo(int... numbers);`

## Testing

Test coverage is a measure of how much of the code is executed during testing. 

### types of testing

* unit testing - focus on small units of code 
* integration testing - test the integration of a larger system
* functional testing - somewhat more end-to-end than unit testing

## TestNG

```
@Test(groups = { "functional", "unit" })
public void testFunctionality() {
  // Test code here
}
```


### Ways to enable/disable tests

* `@Test(enabled=false)`
* exclude/include in testng.xml
* using groups
* `@Ignore`

### testng.xml

#### running the tests

```
java org.testng.TestNG testng.xml
java org.testng.TestNG -d /path/to/output/dir testng.xml
java org.testng.TestNG -suitname suiteName testng.xml
```

* listeners - classes that will perform custom actions on test events

```xml
<test name="Test Example">
  <parameter name="username" value="testuser"/>
  <parameter name="password" value="testpassword"/>
  <classes>
    <class name="com.example.tests.TestClass">
      <methods>
        <include name="testLogin"/>
      </methods>
    </class>
  </classes>
</test>
```

```java
public class TestClass {
  @Test
  @Parameters({"username", "password"})
  public void testLogin(String username, String password) {
    // Implementation to test login with given username and password
  }
}
```



### Data provider

refers to a source of test data used to parameterize tests.

```java
import org.testng.annotations.DataProvider;
import org.testng.annotations.Test;

public class DataProviderExample {

  @DataProvider(name = "userData")
  public static Object[][] userData() {
    return new Object[][] {
      {"user1", "password1"},
      {"user2", "password2"},
      {"user3", "password3"}
    };
  }

  @Test(dataProvider = "userData")
  public void testWithDataProvider(String username, String password) {
    // Perform test using the provided data
    System.out.println("Username: " + username + " Password: " + password);
  }
}
```

Hey, I have a somewhat difficult question. After next week's progress meeting, do you think
I can expect to get assigned to a project fairly quickly (let's say up to a month), or is there
a significant change that it will take longer? I'd like to consider doing some odd jobs in between
and possibly go skiing and even a rough estimate would help me a lot. 

If you're not the right person to ask such a question, please let me know who should I contact ;)
