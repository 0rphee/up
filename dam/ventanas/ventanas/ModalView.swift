//
//  ModalView.swift
//  ventanas
//
//  Created by roger on 10/02/25.
//

import SwiftUI

struct ModalView: View {
    @Environment(\.presentationMode) var presentationMode:
        Binding<PresentationMode>
    var body: some View {
        VStack {
            Text("Hola")

            Button(action:{
                self.presentationMode.wrappedValue.dismiss()
            }){
                Text("aaa")
            }
        }
    }
}

#Preview {
    ModalView()
}
