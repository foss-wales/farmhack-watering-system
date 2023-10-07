# Farmhack Watering System

The watering system we created on the farmhack at the Organic Growers Gathering 2023.

## Hardware Requirements

- Arduino (we use the Nano) from [Aliexpress](https://www.aliexpress.com/item/32915861640.html?spm=a2g0o.productlist.main.3.6be56f377Gc877&algo_pvid=d221dbed-ea56-4897-85c3-898387cb2ec8&algo_exp_id=d221dbed-ea56-4897-85c3-898387cb2ec8-1&pdp_npi=3%40dis%21GBP%212.23%211.89%21%21%21%21%21%40211bea6216845643713245738d07ea%2112000027206340064%21sea%21UK%21195802511&curPageLogUid=JQ1FXJN9cAJU)
- 5V 1A power supply, could be USB. (0.5A does not work)
- L293d from [Aliexpress](https://www.aliexpress.com/item/1005005989900321.html?spm=a2g0o.productlist.main.9.5b56kIL3kIL3YH&algo_pvid=2d6590f2-7994-4b45-bafa-48d26f7fb863&aem_p4p_detail=202310070551052056987919024460000078034&algo_exp_id=2d6590f2-7994-4b45-bafa-48d26f7fb863-4&pdp_npi=4%40dis%21GBP%211.17%211.13%21%21%2110.08%21%21%4021038edc16966830657447281eb1e8%2112000035202323845%21sea%21UK%21195802511%21&curPageLogUid=fLHj9Z6POS77&search_p4p_id=202310070551052056987919024460000078034_1)
- [Electric Solenoid Valve][valve]
- jumper cables
- USB-cable
- breadboard for prototyping
- 

## References

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

The [LH293d PDF][lh293d] drives the valve because the Arduino cannot provide enough current to switch it.


## Setup

Install the Arduino software.
<!--Install the `Arduino Low Power` library from the libraries manager: `Tools` -> `Manage Libries...`. -->



[valve]: https://www.amazon.co.uk/dp/B08XK896N4?psc=1&ref=ppx_yo2ov_dt_b_product_details
[lh293d]: https://www.ti.com/product/L293D



