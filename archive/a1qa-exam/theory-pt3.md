# Theory notes part 3

## DBMS

```
SELECT t1.value, table2.value
FROM table1 as t1
INNER JOIN table2
ON t1.mutual_key = table2.mutual_key;
```

* `LIMIT`

database connection:
`jdbc:mysql://hostname:port/database_name?user=username&password=password`

* inner join - only matching rows
* right/left join - all connected rows + unconnected from right/left
* full join - all rows (including unmatched)
^
* mysql and sqlite don't support joins

### CRUD

* CREATE (insert, PUT/POST)
* READ (retrieve) (select, GET)
* UPDATE (update, POST/PUT/PATCH)
* DELETE (delete, DLETE)

## Network

HTTPS uses SSL or TLS to encrypt the data before it's transmitted. HTTP uses port 80, HTTPS - 443.

Shared resources and permissions - within networks and user groups. Users can have different permissions (read, write, execute)

Proxies may enchance connection speed and reduce bandwith with cache. they enable activity logging and limiting. Only a proxy with a VPN (encrypted connection) can ensure a truly secure connection.

MAC adress is a unique, hexadecimal network device identifier. First 3 bytes
identify the manufacturer, last 3 bytes - the device itself. IP's may change,
MAC adresses don't. Network devices need both to connect. Adresses > IPs > MAC
adresses. The chained devices/routers first get each others IPs, then request
the MAC adess via an ARP request and finally connect.

* 00-04-51... - windows
* 00:04:5a... - linux & mac
* 0003.4440.2340... - cisco

To see the mac address, use `ipconfig /all` on windows or `ifconfig -a` on unix.

DNS (domain name system) checks the names in a **resolver** cache first, then to the root server.
the **root** server forwards th request to a **tld**  server which stores top level domain adress
info (.com, .org etc), then the tld server forwards it to the **name** server.

DHCP (dynamic host config protocol) is a system for automatically assigning IP
adresses to MAC adresses (as opposed to doing it manually). it also assigns **a
subnet mask, default gateawy and dns server**.

Default gateway: A default gateway is a network router that connects devices on
a local network to the Internet or other wide area networks.

Subnet mask: A subnet mask is a 32-bit number that helps to divide a larger
network into smaller subnets. It is used to divide a network into different
subnets so that network traffic can be more easily controlled and managed.

`ping` - tests network connectivity and dns issues - sends datapackets and tracks time if a reply was recieved. tracks
lost packets. diagnoses `network congestion`.

`tracert` - traces the route

### `ipconfig`

displays ip. subnet mask and default gateway. ipv4 shown here private, the device is
assigned a public one elsewhere.

* `/flushdns` - delete the "dns cache"
* `/displaydns` - time to live

## CMD

* cd\ - navigate do drive root
* d: - switch to drive d
* dir - list directory contents (like `ls`)
* ren - rename
* copy - cp file
* xcopy /s - `cp -r`, skip empty folders
* xcopy /i - create folders if they don't exist
* del /h - delete files, including hidden
* rd - rmdir

## Virtual machines

Soft/hard snapshots - on a running/powered off machine.

NAT (Network Address Translation): NAT allows a virtual machine to connect to
the Internet or other networks using **the host computer's IP address.** This type
of connection is useful for testing or running software that needs Internet
connectivity, but it does not provide direct access to the host computer's
network resources. Useful for "testing".

Bridged: A bridged connection allows the virtual machine to connect to the host
computer's network **as if it were a physical machine on the network.** This type
of connection allows the virtual machine to be assigned its own IP address and
to communicate directly with other machines on the network. Useful for mail servers.

Host-only: A host-only connection allows the virtual machine to communicate
only with the host computer AND OTHER VIRTUAL MACHINES ON THE HOST, and not
with other machines on the network. This type of connection is useful for
testing or running software that does not need
to communicate with other machines on the network. Useful for isolation and
penetration testing.

Internal network: An internal network allows the virtual machine to communicate
only with other virtual machines on the same host computer. This type of
connection is useful for creating isolated networks for testing or development.

### Guest Additions benefits

* Mouse pointer integration
* Shared folders
* Better video support, resizing windows
* Accelerated video performance, 3D graphics acceleration
* Seamless windows
* Host/guest communication channles
* Time synchronization
* Shared clipboard
* Automated logins credentials passing.

## Windows

An application is a program that users interact with on the desktop. A process
is an instance of an executable program running. A service is a background
process that does not interact with the desktop.

RDP - easy on the same network, harder on different networks. Supported only in higher-end windwos editions, and only
windows-windows.

### taskkill

```
tasklist :: or powershell Get-Process

taskkill /PID <PID> /F
taskkill /IM <process name> /F
```

### Windows Domain Controller (DC)

a server with an AD DS / active directory domain services role installed.
There can be multiple controllers, but only one primary one.

When a PC connects, it first tries to find a local account on the pc, then look for it in the dc's active dircetory.

Group policies contain group policy objects (GPO) that manage AD objects

#### Active directory (AD) objects

* users
* computers
* printers
* File shares
* groups
* group objects(admins, users etc.)

## Selenium


### Actions

* moveToElement()
* pause(Duration.ofSeconds())
* clickAndHold()
* pause()
* sendKeys()
* perform()

### Exceptions

* StaleElementReferenceException
* NoSuchElementException
* ElementNotIntractableException
* TimeoutException
* InvalidSelectorException
* WebDriverExceptions
* ElementClickInterceptedException
(element receiving the events is obscuring the element that was requested to be clicked.)

### Cookies

```
driver.manage().addCookie(new Cookie("foo", "bar"));
Cookie foo = driver.manage().getCookieNamed("foo");
driver.manage().deleteCookieNamed("foo"); // OR .deleteCookie(foo);
Set<Cookie> cookies = driver.manage().getCookies();
```

### Waits

#### in Aquality:

* `void waitForTrue`
* `boolean waitFor`
* `<T> T waitFor`

#### in vanilla Selenium

```
// explicit, returns TimeoutExceptions
WebElement firstResult = new WebDriverWait(driver, Duration.ofSeconds(10))
        .until(ExpectedConditions.elementToBeClickable(By.xpath("//a/h3")));
// implicit, return NoSuchElementException
driver.manage().timeouts().implicitlyWait(Duration.ofSeconds(10));
```

### Locators

* use `By.name()`, `By.linkText()`, `By.PartialLinkText()`

* Use unique and stable locators: When identifying elements, it is important to
  use unique and stable locators that are not likely to change over time. For
  example, using an element's ID attribute is generally more stable than using
  its CSS class.
* Use multiple locators: When possible, use multiple locators to identify
  elements. This can help to ensure that the test will still work even if one
  of the locators becomes invalid.
* Use relative paths: When identifying elements that are nested within other
  elements, it is best to use relative paths to identify the elements rather
  than absolute paths. This can help to make the test more resilient to changes
  in the structure of the page.
* Avoid using indexes: When identifying elements, it is best to avoid using
  indexes as a way to locate elements. Indexes can change frequently, and they
  make the tests more fragile.
* Use CSS selector: CSS selectors are more efficient than XPath when it comes
  to the performance of the test. CSS selectors are faster than XPath in most
  cases.
* Use JavaScript Executor: JavaScript Executor allows you to execute JavaScript
  code within the browser, and can be used to identify elements that are not
  normally accessible through the DOM.
* Use the Page Object Model: The Page Object Model is a design pattern that
  allows you to encapsulate locators and methods related to a specific page or
  component of a website. This helps to make your tests more maintainable, and
  your locators more reusable.
* Keep locators in a separate file: Keep the locators in a separate file, to
  make it easy to maintain and update them, also this is useful for reusability
  across different test cases
* Use of locator priority: Use locator priority to find the element, for
  example, use ID first, then name, then CSS, then Xpath

### Frames


```
//Store the web element
WebElement iframe = driver.findElement(By.cssSelector("#modal>iframe"));

//Switch to the frame using WebElement
driver.switchTo().frame(iframe);

//Using the ID
driver.switchTo().frame("buttonframe");

//Or using the name instead
driver.switchTo().frame("myframe");

// Return to the top level (leave the frame)
driver.switchTo().defaultContent();
driver.switchTo().parentFrame();
```

### Window settings

```
WebDriver driver = new ChromeDriver();

// Set window size
Dimension dimension = new Dimension(800, 600);
driver.manage().window().setSize(dimension);


// Set window position
Point point = new Point(200, 200);
driver.manage().window().setPosition(point);
```

### Misc

* `element.getAttribute("innerHTML")` and `driver.getPageSource();`
* `.accept()`, `.dismiss()` and `.sendKeys(), getText()` alert methods

```
SoftAssert softAssert = new SoftAssert();
softAssert.assertEquals(1, 2);
softAssert.assertTrue(false);
softAssert.assertAll();
```

### Navigation

```
driver.navigate().back();
driver.navigate().forward();
driver.navigate().refresh();
```