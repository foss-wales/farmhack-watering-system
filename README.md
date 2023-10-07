# Farmhack Watering System

The watering system we created on the farmhack at the Organic Growers Gathering 2023.

## References

- [valve]

### Valve

The [valve] is described like this:

> As per header, the product itself is excellent, well-made and extremely reliable. However, it is handicapped by absolutely abysmal documentation, which could be very frustrating. I have a serious background in IoT and electronics, but I were almost on the verge of returning it, before figuring out how to make it work. Once I understood it - it is perfect.
> 
> 1. This is an indirect pilot operated asymmetrical valve. It means that it only operates in one direction (watch the arrow on the body showing the direction of slow of water. It also requires a minimum pressure differential of at least 1 bar (in my experience). The more water pressure is applied - the better it will work. It works perfectly with standard UK water mains and garden hoses, but not with micro irrigation systems (not enough pressure)
> 2. If the intake water pressure is lost - the valve will automatically shut
> 3. The thread is UK standard BSP 1/2 inch
> 4. The box includes mesh water filter
> 5. The valve is latching. It means that you only need to apply power to switch its state (open or close) and then it stays in this state indefinitely (as far as water flow continues) - so extremely power efficient
> 6. Control voltage could be anything from 3.3 to 5 volts DC. In my experience 4-5 volts are 100% reliable, as the voltage drops, the operations become less reliable - the valve will sometimes misfire, but eventually will work.
> 7. When switching, the valve draws a significant amount of current - 300-500mA depending on water pressure. It could be operated from a stack of conventional AA batteries, but NOT from GPIO of small IoT devices - you will need a relay.
> 8. To switch state, all you need is to apply a a short (circa 30ms) DC pulse to the two wires. Applying positive to RED and negative to BLACK opens the valve, reversing the polarity closes the valve
> 9. 30 ms pulse is sufficient, however you could apply a longer one - even a few seconds. The only caveat is that you do should not leave it on for prolonged periods of time (hours) - you will eventually damage (burn) solenoid.
> 10. The valve is sensitive to orientation - it must be positioned with the main body parallel to earth an the top assembly vertical. Significant deviations from this angle will affect operations - the valve might not be able to open or close fully.
> 11. The valve is very fast and extremely quiet. The click of switching could only be heard if you are standing right next to it and listening intently.

### Motor Driver

[LH293d PDF](https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1696650171249&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D).



## Setup

Install the Arduino software.



[valve]: https://www.amazon.co.uk/dp/B08XK896N4?psc=1&ref=ppx_yo2ov_dt_b_product_details




