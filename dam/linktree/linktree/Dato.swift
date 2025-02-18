//
//  Dato.swift
//  linktree
//
//  Created by roger on 14/02/25.
//

import SwiftUI

struct Dato: View {
    var body: some View {
        VStack(spacing: 20) {
            Text("Dato curioso").bold().font(.title)
            Text("Soy vegetariano y me gustan las pizzas").multilineTextAlignment(.leading)
        }
        .padding()
        .navigationTitle("Dato curioso")
    }
}

#Preview {
    Dato()
}
