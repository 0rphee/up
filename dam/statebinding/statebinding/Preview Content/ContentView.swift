//
//  ContentView.swift
//  statebinding
//
//  Created by roger on 17/02/25.
//

import SwiftUI

struct ContentView: View {
    @State private var x = "Título original"
    var x1 = 2
    @State private var show = true
    @State private var count = 0
    @State private var numeroMoneda = 15
    @State private var numeroMoneda2 = "0"
    @State private var showSheet = false

    func test() -> Int {
        var x2 = 4
        // Variables exteriores requieren @State
        x = "Cambiando valor"
        x2 = 10
        return x2
    }

    var body: some View {
        VStack {
            Text(x).font(.title)
            HStack {
                Button(action: {
                    show.toggle()

                    if show {
                        count -= 1
                    } else {
                        count += 1
                    }

                }) {
                    let image = show ? "heart" : "heart.fill"
                    Image(systemName: image).foregroundColor(.red).font(
                        .largeTitle)
                }
                Text(String(count)).font(.title2).bold()
                Button(action: {
                    numeroMoneda = numeroMoneda + Int(numeroMoneda2)!
                }) {
                    Image(systemName: "dollarsign.circle.fill").foregroundStyle(
                        .yellow
                    ).bold().font(.largeTitle)
                }
                Text(String(numeroMoneda)).bold().font(.title2)
            }

            TextField("Título", text: $x)
            TextField("Valor", text: $numeroMoneda2).textFieldStyle(
                RoundedBorderTextFieldStyle()
            ).keyboardType(.numberPad)

            vista2(x: $x)
            Button(action: { showSheet.toggle() }) {
                Text("Abrir vista")
            }
        }.padding().sheet(isPresented: $showSheet) {
            vista3(x: $x)
        }
    }
}

struct vista2: View {
    @Binding var x: String
    var body: some View {
        Text(x).font(.largeTitle).foregroundStyle(.red)
    }
}

struct vista3: View {
    @Binding var x: String
    var body: some View {
        Button(action: {
            x = "Nuevo título desde la vista 3"
        }) {
            Text("Cambiar título")
        }
    }
}

#Preview {
    ContentView()
}
