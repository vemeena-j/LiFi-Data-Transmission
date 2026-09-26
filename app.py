import streamlit as st
import time

st.set_page_config(
    page_title="Li-Fi Data Transmission",
    page_icon="💡",
    layout="centered"
)

st.title("💡 Li-Fi Based Data Transmission")
st.write("Light Fidelity (Li-Fi) Data Transmission Simulator")

st.divider()

message = st.text_input(
    "Enter a message to transmit:",
    placeholder="Type something like HELLO"
)

if st.button("🚀 Transmit Data"):

    if message.strip() == "":
        st.warning("Please enter a message.")
    else:

        # Convert text into 8-bit binary
        binary_data = " ".join(
            format(ord(char), "08b") for char in message
        )

        st.subheader("📡 Transmission")

        st.write("Original Message:")
        st.code(message)

        st.write("Binary Data:")
        st.code(binary_data)

        st.write("💡 Virtual LED Transmission")

        led = st.empty()
        progress = st.progress(0)

        # Remove spaces for bit-by-bit transmission
        clean_binary = binary_data.replace(" ", "")

        total_bits = len(clean_binary)

        # Simulate LED transmission
        for i, bit in enumerate(clean_binary):

            if bit == "1":
                led.markdown(
                    "<h1 style='text-align:center;'>💡 LED ON</h1>",
                    unsafe_allow_html=True
                )
            else:
                led.markdown(
                    "<h1 style='text-align:center;'>⚫ LED OFF</h1>",
                    unsafe_allow_html=True
                )

            progress.progress((i + 1) / total_bits)
            time.sleep(0.03)

        st.success("✅ Data transmitted successfully!")

        # Convert received binary back to text
        received_message = ""

        for i in range(0, len(clean_binary), 8):
            byte = clean_binary[i:i + 8]
            received_message += chr(int(byte, 2))

        st.subheader("📥 Received Data")

        st.code(received_message)

        if received_message == message:
            st.success(
                "🎉 Transmission Successful — "
                "Message Received Correctly!"
            )
        else:
            st.error("❌ Transmission Error")

st.divider()

st.caption(
    "Li-Fi uses light to transmit digital data."
)